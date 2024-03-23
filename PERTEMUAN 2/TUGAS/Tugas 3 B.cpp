// MERGE SORT
#include <iostream> // header input - output
using namespace std;

// function untuk menggabungkan 2 sub-array yang diurutkan menjadi satu
void merge (int arr[], int l, int m, int r) 
{
	int x, y, z;
	int n1 = m - l + 1; // penghitungan ukuran sub-array kiri L[]
	int n2 = r - m; // penghitungan ukuran sub-array kanan R[]
	
	int L[n1], R[n2]; // pendeklarasian dua array sementara untuk menyimpan elemen sub-array kiri dan kanan
	for (x = 0; x < n1; x++) // menginisialisasi sub-array kiri L[] dengan elemen dari array utama arr[]
        L[x] = arr[l + x]; 
	for (y = 0; y < n2; y++) // menginisialisasi sub-array kanan R[] dengan elemen dari array utama arr[]
	    R[y] = arr[m + 1 + y];
	
	// dipergunakan untuk melacak posisi di sub-array kiri L[], sub-array kanan R[], dan array gabungan arr[]
	x = 0;
	y = 0;
	z = l;
	
	// pembandingan elemen dari kiri dan kanan, lalu menggabungkannya ke dalam array utama arr[]
	while(x < n1 && y < n2) 
	{
		if (L[x] <= R[y])  // jika benar, elemen dari sub-array kiri disalin ke array gabungan arr[]
		{
			arr[z] = L[x];
			x++; // lalu x di increment
		}
		else 
		{
			arr[z] = R[y]; // jika salah, elemen dari sub-array kanan dimasukkan ke array gabungan arr[]
			y++; // lalu y di increment 
		}
		z++; // jika kedua kasus benar, indeks z bertambah untuk berpindah ke posisi berikutnya dalam array gabungan arr[]
	}
	// menyalin elemen yang tersisa dari sub-array kiri L[] ke array gabungan arr[]
	while (x < n1) 
	{
		arr[z] = L[x];
		x++;
		z++;
	}
	// penyalinan elemen yang tersisa dari sub-array kanan R[] ke array gabungan arr[]
	while (y < n2) 
	{
		arr[z] = R[y];
		y++;
		z++;
	}
}

// fungsi untuk mengurutkan array secara rekursif menggunakan pengurutan gabungan
void mergesort(int arr[], int l, int r)
{
	if (l < r) 
	{
		int m = l + (r - l) / 2; // memastikan array dibagi menjadi dua bagian yang sekiranya sama
		
		mergesort (arr, l, m); // memanggil mergesort secara rekursif untuk bagian kiri array
		mergesort (arr, m + 1, r); // memanggil mergesort secara rekursif untuk bagian kanan array
		
		merge(arr, l, m, r); // penggabungan dua bagian array yang diurutkan
	}
}

// function untuk menampilkan elemen array
void show(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++) 
		cout << A[i] << " ";
}

int main() {
    int size;
    cout << "Masukan banyak data : ";
    cin >> size; // user memasukkan banyak data (panjang array) yang diinginkan

	for (int i = 0; i < size; i++)
	{
		cout << "\nMasukkan Data Array ke - " << i << " = ";
		cin >> arr[i]; // user memasukkan elemen angka pada array
	}

    mergesort(arr, 0, size - 1); // memanggil fungsi mergesort untuk mengurutkan array

    cout << "Hasil : ";
    show(arr, size); // menampilkan elemen array yang sudah diurutkan


    return 0;
}
