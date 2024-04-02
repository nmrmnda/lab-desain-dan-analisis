#include <iostream>
using namespace std;

class mtk{
	private:
		float an1;
		float an2;
	public:
		void setPTM(int a, int b){
			an1 = a;
			an2 = b;
		}
		
		int pt(){
			return an1 + an2;
		}
		int px(){
			return an1 * an2;
		}
		int pk(){
			return an1 - an2;
		}
		void pbl(){
			cout<<"Hasil pembagian : ";
			if(an2 == 0){
				cout<<"Error: pembagian dengan nol tidak dapat dilakukan.\n";
			}else{
				cout<<an1/an2;	
			}
		}
//		float pb(){
//			if(an2 == 0){
//				return "Error: pembagian dengan nol tidak dapat dilakukan.";
////				return 0;
//			}else{
//				return an1/an2;
//			}	
//		}
};

int main(){
	mtk mate;
	int x, y;
	
	cout<<"Masukkan angka pertama : ";
	cin>>x;
	cout<<"MAsukkan angka kedua : ";
	cin>>y;
	
	mate.setPTM(x,y);
	
	cout<<"Hasil Pertambahan : "<<mate.pt()<<endl;
	cout<<"Hasil Pengurangan : "<<mate.pk()<<endl;
	cout<<"Hasil Perkalian : "<<mate.px()<<endl;
	mate.pbl();
	
	
}
