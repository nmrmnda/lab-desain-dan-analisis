#include <iostream> 
using namespace std;

class contoh { //penentuan sebuah class yaitu 'contoh'
	private: //menandakan kode dibawah nya hanya bisa diakses oleh class itu sendiri
		int nilai; //menentukan sebuah variabel 'nilai' dengan tipe data 'integer'
		public: //menandakan kode dibawahnya dapat diakses luar class
			contoh (int n) { //menentukan constructor class 'contoh' yang menerima parameter "n"
				nilai = n; //menghasilkan nilai dari parameter yang diinputkan ke variabel
			}
			
			
			int getNum(){ //menentukan fungsi 'getNum' yang mengembalikan variabel 'nilai'
				return nilai; //mengembalikan variabel dalam fungsi
			}
}; //menutup class 

int main(){ //fungsi utama
	contoh obj(10); //membuat objek 'obj' dari class 'contoh' dengan nilai 10
		cout<<"nilai yang diinput: "<<obj.getNum()<<endl; //tampilkan pesan yang menggunakan nilai yang diinput pada objek melalui fungsi
		return 0; 
	}
