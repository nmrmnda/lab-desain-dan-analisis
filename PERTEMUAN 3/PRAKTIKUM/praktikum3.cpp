#include <iostream>
#include <string>
using namespace std;

class Mahasiswa{
	private:
	string Mahasiswa;
	int NPM;
	
	public:
	void setNPM (int n){
		NPM = n;
	}
	
	void setMahasiswa (string s){
		Mahasiswa = s;
	}
	
	int getNPM(){
		return NPM;
	}
	
	string getMahasiswa(){
		return Mahasiswa;
}
};
int main(){
	Mahasiswa data;
	int b;
	string a;
	
	cout<<" Masukkan nama mahasiswa : ";
	getline (cin, a);
	
	cout<<" Masukkan NPM Mahasiswa : ";
	cin>>b;
	
	
	Mahasiswa Mahasiswa;
	
	Mahasiswa.setMahasiswa (a);
	Mahasiswa.setNPM (b);
	cout<<"\n Data Mahasiswa "<<endl;
	cout<<" Nama : "<<Mahasiswa.getMahasiswa()<<endl;
	cout<<" NPM : "<<Mahasiswa.getNPM()<<endl;
	
	return 0;
	
}

//getline (cin, mahasiswa);
