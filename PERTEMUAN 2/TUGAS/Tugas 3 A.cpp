// QUICK SORT 
#include <iostream> // header input - output 
using namespace std;

// fungsi untuk menukar 2 elemen didalam array
void swap (int arr[], int pos1, int pos2) { // mendefinisikan fungsi untuk menukar elemen di array
	int temp; // mendeklarasikan temp dengan tipe data integer
	temp = arr[pos1]; // memasukkan nilai arr[pos1] kedalam temp
	arr[pos1] = arr [pos2]; // memasukkan nilai arr[pos2] kedalam arr[pos1]
	arr[pos2] = temp; // memasukkan nilai temp kedalam arr[pos2]
}

// fungsi untuk mempartisi array disekitar elemen pivot
int partition (int arr[], int low, int high, int pivot) { // pengambilan array, indeks rendah, indeks tinggi, dan nilai pivot
int i = low; // mendeklarasikan integer i sebagai index low
int j = low; // mendeklarasikan integer j sebagai index low
// mengulangi array dari indeks rendah ke tinggi
while (i <= high) { 
	if (arr[i] > pivot) { // jika elemen yang ada pada index i lebih besar dari pivot, 'i' di increment
		i++;
	}
	else {  // jika tidak, elemen pada indeks 'i' ditukar dengan elemen pada indeks j, dan 'i' dan 'j' di increment
	swap (arr, i, j);
	i++;
	j++;
	}
}
return j-1; // pengembalian posisi pivot setelah dipartisi
}

// fungsi untuk menjalankan quick sort
void quicksort(int arr[], int low, int high) {
// jika low lebih kecil dari high, menunjukkan bahwa sub=array memiliki lebih dari satu elemen, maka dilakukan langkah partisi untuk mencari posisi pivot
	if (low < high) { // proses pengecek-kan ada elemen yang harus diurutkan
		int pivot = arr[high];
		int pos = partition(arr, low, high, pivot);
		
		quicksort(arr, low, pos-1);
		quicksort(arr, pos+1, high);
	// dipanggil secara rekursif pada sub-array kiri (rendah ke pos-1) dan sub-array kanan (pos+1 ke tinggi), tidak termasuk pivot itu sendiri
	}

}

int main ()
{
	int n; 
	cout << "Tentukan panjang array = "; // pengarahan user untuk mengimput panjang array
	cin>> n;
	
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // pengimputan panjang array
	}
	quicksort(arr, 0, n-1); // memanggil fungsi quicksort untuk mengurutkan dan menampilkan array yang diurutkan
	cout << "Berikutnya adalah array yang telah di sortir = "; 
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
}

