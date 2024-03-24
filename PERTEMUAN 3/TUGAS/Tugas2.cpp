#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string peminjam;
    string buku;

public:
    void setNama(string n) {
        peminjam = n;
    }

    void setBuku(string m) {
        buku = m;
    }

    string getNama() {
        return peminjam;
    }

    string getBuku() {
        return buku;
    }
};

int main() {
    Person p;
    string name;
    string book;

    cout << "Masukkan Nama Peminjam: ";
    getline(cin, name);
    p.setNama(name);

    cout << "Buku yang dipinjam: ";
    getline(cin, book);
    p.setBuku(book);
    
    cout<<endl;

    cout << "Nama: " << p.getNama() << endl;
    cout << "Buku yang dipinjam: " << p.getBuku() << endl;

    return 0;
}

