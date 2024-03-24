#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
public:
    string NAMA;
    int NPM;

public:
    void setNama(string n) {
        NAMA = n;
    }

    void setNPM(int p) {
        NPM = p;
    }

    string getNama() {
        return NAMA;
    }

    int getNPM() {
        return NPM;
    }
};

int main() {
    mahasiswa Mahasiswa[5]; 
    string nm;
    int npm;

    for (int i = 0; i < 5; i++) {
    cout<<"Masukkan nama mahasiswa "<< i + 1 <<": ";
    getline(cin, nm);
    Mahasiswa[i].setNama(nm);

    cout<<"Masukkan NPM mahasiswa "<< i + 1 <<": ";
    cin>>npm;
    cin.ignore();
    Mahasiswa[i].setNPM(npm);
    }

    for (int i = 0; i < 5; i++) {
        cout<<"\nMahasiswa "<< i + 1 << ": \n";
        cout<<"Nama : "<<Mahasiswa[i].getNama()<< endl;
        cout<<"NPM : "<<Mahasiswa[i].getNPM()<< endl;
    }

    return 0;
}
