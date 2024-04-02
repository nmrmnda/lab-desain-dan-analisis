#include <iostream>
using namespace std;

int pertambahan(int an1, int an2){
//	int m = 0, n = 1; 
//	int c = an1[m] + an1[n];
	return an1 + an2;
	
}

int pengurangan(int an1, int an2){
//	int m = 0, n = 1;
//	int c = ar[m] - ar[n];
	return an1 - an2;
}

int perkalian(int an1, int an2){
//	int m = 0, n = 1;
//	int c = an1[m] * an1[n];
	return an1 * an2;
}

float pembagian(float an1, float an2){
	int m = 0, n = 1;
	
	if(an2 == 0){
		cout<<"Error: Pembagian dengan nol tidak dapat dilakukan. "; 
	}else{
//		int c = ar[]=m / ar[]=n;
		
		return an1 / an2;
	}
}

int main(){
	int ar, an;
	char smbl, yn;
	
	do{
		cout<<"Masukan dua angka : ";
		cin>>ar>>an;
//		for(int i = 0; i < 2; i++){
//			cin>>ar[i];
//		}
		
		cout<<"Pilih Operasi"<<endl
			<<"(Pertambahan (+), Pengurangan (-),/n Pekalian (*), Pembagian(/)): ";
		cin>>smbl;
		cout<<endl;
		

		switch(smbl) {
			case '-' :
				cout<<"Hasil Pengurangan: "<<pengurangan(ar,an);
			break;
			case '+' :
				cout<<"Hasil Petambahan: "<<pertambahan(ar,an);
			break;
			case '*' :
				cout<<"Hasil Perkalian: "<<perkalian(ar,an);
			break;
			case '/' :
				cout<<"Hasil Pembagian: "<<pembagian(ar,an);
			break;
		}
		
		cout<<endl<<endl;
		
		cout<<"Apakah Anda ingin melanjutkan (y/n)? ";
		cin>>yn;
	}
	while(yn == 'y' || yn == 'Y');
}



