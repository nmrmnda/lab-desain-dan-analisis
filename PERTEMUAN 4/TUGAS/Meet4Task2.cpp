#include <iostream>
#include <string>
using namespace std;

class Contacts {
private:
    string nm[10];
    string notelp[10];
    int contact;

public:
    Contacts() : contact(0) {}

    void tambah(string x, string h) {
        if (contact < 10) {
            nm[contact] = x;
            notelp[contact] = h;
            contact++;
        } 
    }

    void display() {
        cout<<"\n Daftar Kontak : "<<endl;
        for (int i = 0; i < contact; i++) {
            cout<<" Kontak ke - "<< i + 1 <<endl;
            cout<<" Nama : "<<nm[i] <<endl;
            cout<<" Nomor Telepon : " <<notelp[i] <<endl;
            cout<<"------------------------------------\n";
        }
    }
};

int main() {
    string w;
    string t;
    char k;
    Contacts person;
    int l = 0;
    
    cout<<" Masukkan kontak ( maksimal 10 kontak ) : \n\n";

    do {
        cout<<" Masukkan nama kontak ke - " << l + 1 << " : ";
        getline(cin, w);
        cout<<" Masukkan nomor telepon kontak ke - "<< l + 1 <<" : ";
        getline(cin, t);
        person.tambah(w, t);
        l++;
  cout<<" Kontak berhasil ditambahkan \n"; 

        cout<<" Tambahkan kontak lagi? (y/n) : ";
        cin>>k;
        cin.ignore();  
        cout<<endl;

    } while (toupper(k) == 'Y' && l < 10);

    if (toupper(k) == 'N') {
        person.display();
    }

    return 0;
}
