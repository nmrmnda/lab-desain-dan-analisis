#include <iostream>
using namespace std;

class data{
	private:
		int usia[100];
		float ipk[100];
		string nama[100];
		
	public:
		data(int a[], string b[], float c[], int j){
			for (int m=0;m<j; m++){
					usia [m]= a[m];
			nama [m]= b[m];
			ipk [m]= c[m];
			}
		
		}
		
		string getnama(int i){
			return nama[i];
		}
		
		float getipk(int i){
			return ipk[i];
		}
		
		int getusia(int i){
			return usia[i];
		}
		
};

int main(){
	int usia[100],a;
	float ipk[100];
	string nama[100];
	
	cout<<"Masukan jumlah mahasiswa : ";
	cin>>a;
	cin.ignore(); 
	cout<<endl;
	
	for(int i=0;i<a;i++){
		cout<<"Mahasiswa ke "<<i+1<<endl;
		cout<<"Nama: ";
		getline(cin, nama[i]); 
		cout<<"Usia: ";
		cin>>usia[i];
		cout<<"IPK: ";
		cin>>ipk[i];
		cin.ignore(); 
		cout<<endl;
	}
	
	data mahasiswa(usia,nama,ipk, a);
	
	for(int i=0; i<a; i++){
		cout << "Nama :" << mahasiswa.getnama(i) << endl;
		cout << "Usia :" << mahasiswa.getusia(i) << endl;
		cout << "IPK :" << mahasiswa.getipk(i) << endl;
	}
	
	return 0;
}
