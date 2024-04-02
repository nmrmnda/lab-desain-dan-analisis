#include <iostream>
using namespace std;

void INS(int data[], int size){
	int z, j, x;
	for(int j = 1; j < size; j++){
		z = data[j];
		int n = j;
		
		while(n > 0 && data[n] < data[n-1]){
//			ar[n+1] = ar[n];
//			n--;
			x = data[n];
			data[n] = data[n-1];
			data[n-1] = x;
			n--;	
		}
//		ar[n+1] = z;
	}
}

void cetak(int arr[], int m){
	for(int i = 0; i < m; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int ar[] = {12, 11, 13, 5, 6};
	int z, x, y, m = 5;
	
	cout<<"Array sebelum diururtkan: "<<endl;
	cetak(ar, m);
	
	INS(ar, m);
	
	cout<<"\n\nArray setelah diururtkan: "<<endl;
	cetak(ar, m);
	 
}
