#include <iostream>
using namespace std;

class Laptop {
	
	private:
		string pemilik;
		string merk;
		
		public:
			Laptop (string var1, string var2){
				pemilik = var1;
				merk = var2;
				
				cout<<" Paket laptop "<<merk<<" milik "<<pemilik<<" sudah dikirim "<<endl;
			}
};

int main(){
	Laptop laptopFadhlan ("Fadhlan", "Asus");
	Laptop laptopRisma ("Risma", "Acer");
	Laptop laptopCarlos ("Carlos", "Lenovo");
	
	return 0;
}
