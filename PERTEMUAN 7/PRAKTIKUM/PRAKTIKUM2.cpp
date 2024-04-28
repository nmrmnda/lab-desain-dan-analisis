#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100;
int nim[N];

int binarySearch (int x, int l, int r) {
	if (r>= l){
		int mid = 1 + (r - l) / 2;
		if (nim[mid] == x)
		return mid;
		if (nim[mid] > x)
		return binarySearch(x, l, mid - 1);
		return binarySearch (x, mid + 1, r);
	}
	return -1;
}

int main(){
	int n;
	cout<<"Masukkan jumlah mahasiswa : ";
	cin>>n;
	
	cout<<"Masukkan NIM mahasiswa : "<<endl;
	for (int i = 0; i < n; i++){
		cin>>n;
	}
	sort (nim, nim + n);
	int x;
	cout<<"Masukkan NIM yang dicari : ";
	cin>>x;
	
	int hasil = binarySearch(x, 0, n- 1);
	if (hasil == 1)
	cout<<"NIM tidak ditemukan"<<endl;
	else
	cout<<"NIM ditemukan pada indeks"<<hasil<<endl;
	
	return 0;
}
