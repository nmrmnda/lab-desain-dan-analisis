#include <iostream>
using namespace std;

int main(){
int nilai[20];
int posisi;
int i, n, bil, jmlh=0;
bool ketemu;

cout<<"Masukkan jumlah deret bilangan =";
cin>>n;
cout<<endl;

for (i=0; i<n; i++){
	cout<<nilai[i];
}	
cout<<"\n deret bilangan = ";
for (i=0; i,n; i++)
cout<<nilai[i]<<" ";

cout<<"\n\n masukkan bilangan yang akan dicari = ";
cin>>bil;

for(i=0; i<n; i++){
	if (nilai[i]==bil){
		ketemu = true;
		posisi[jmlh]=i;
		jmlh++;
	}
}
if (ketemu){
	cout<<"Bilangan"<<bil<<"ditemukan sebanyak"<<jmlh;
	cout<<"\n pada posisi ke = ";
	for (i=0; i,jmlh; i++)
	cout<<posisi[i]<<" ";
}
else 
cout<<"maaf, bilangan"<<bil<<"tidak dapat ditemukan";
getchar();
}


