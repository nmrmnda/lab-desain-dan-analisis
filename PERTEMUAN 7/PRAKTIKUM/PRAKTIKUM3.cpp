#include <iostream>
#include <algorithm>
#include <conio.h>
#include <string.h>
using namespace std;

struct Barang{
	string nambar;
	int harga;
};

int cek(string brg,const Barang daftarbarang[]){
	int a = 0;
	for(int i = 0; i < 5; i++){
		if(daftarbarang[i].nambar == brg){
			return i;
		}
	}
}

int main(){
	int a = 0, *i;
	bool ketemu;
	string brg;
	Barang daftarbarang[5] = {
	{"Buku", 5000}, 
	{"Pensil", 1000}, 
	{"Pulpen", 2000}, 
	{"Penghapus", 500}, 
	{"Penggaris", 1500}
	};
	
		
	cout<<"Masukan Nama Barang yang Dicari = ";
	cin>>brg;	
	
	a = cek(brg, daftarbarang);
	
	if(cek != 0){	
		cout<<"Barang "<<brg<<" Ditemukan dengan harga Rp"<<daftarbarang[a].harga;
	}else{
		cout<<"Barang "<<brg<<" tidak ditemukan dalam daftar\n";
	}
	
}


