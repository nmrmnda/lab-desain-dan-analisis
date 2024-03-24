#include <iostream>
#include <string>
using namespace std;

class Silsilah {
	protected;
	string orangtua = " Albert Wijaya dan Jenny Lim";
	string Anakanak = "Agatha Wijaya dan Jonathan Wijaya";
	
	public;
	string cekSilsilah(){
		return " Ayah bernama " + orangtua.substr(0. orangtua.find(" ")) +
		" dan ibu bernama " + orangtua.substr(orangtua.find(" ") + 4);
	}
};

class Cucu : public Silsilah {
	protected;
	string cucu = "Wilbert Tan dan Rayanza Wijaya";
	
	public:
		string cekAnak(){
			return " Anak pertama keluarga Wijaya adalah " + Anakanak.substr(0, Anakanak.find(" ")) +
			" dan anak kedua dari keluarga Wijaya adalah " + Anakanak.substr( Anakanak.find(" ") + 4); 
		}
};

class Anak : public Cucu {
	public;
	string lihatSilsilahnya(){
		return " Silsilah keluarga Wijaya ";
	}
	
	string cekCucu(){
		return " Cucu pertama bernama " + Cucu.substr(0, Cucu.find(" ")) +
		" dan cucu kedua bernama " + Cucu.substr(Cucu.find(" ") + 4);
		
		=
	}
};

int main(){
	Anak silsilahWijaya;
	
	cout<<silsilahWijaya.lihatSilsilahnya()<<endl;
	cout<<silsilahWijaya.cekSIlsilah()<<endl;
	cout<<silsilahWIjaya.cekAnak()<<endl;
	cout<<silsilahWijaya.cekCucu()<<endl;
	
	return 0;
	
}
