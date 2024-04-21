#include <iostream>
using namespace std;

class BangunDatar {
public:
    virtual float HL() = 0; 
};

class PersegiPanjang : public BangunDatar {
private:
    float panjang, lebar;
public:
    PersegiPanjang(float p, float l) : panjang(p), lebar(l) {}
    float HL() override {
        return panjang * lebar;
    }
};

class Segitiga : public BangunDatar {
private:
    float alas, tinggi;
public:
    Segitiga(float a, float t) : alas(a), tinggi(t) {}
    float HL() override {
        return 0.5 * alas * tinggi;
    }
};

int main() {
    float PP, LP, AS, TS;

    cout << "Masukkan panjang persegi panjang: ";
    cin >> PP;
    cout << "Masukkan lebar persegi panjang: ";
    cin >> LP;

    cout << "Masukkan alas segitiga: ";
    cin >> AS;
    cout << "Masukkan tinggi segitiga: ";
    cin >> TS;
    cout<<endl;

    PersegiPanjang persegi(PP, LP);
    Segitiga segitiga(AS, TS);
    
    cout<<" Luas Bangun datar: "<<endl;
    cout << "Luas persegi panjang: " << persegi.HL() << endl;
    cout << "Luas segitiga: " << segitiga.HL() << endl;

    return 0;
    
}

