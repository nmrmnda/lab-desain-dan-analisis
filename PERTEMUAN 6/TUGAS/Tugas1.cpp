#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {
protected:
    string nama;
    int umur;
    string jurusan;
    string fakultas;
public:
    Mahasiswa(string _nama, int _umur, string _jurusan, string _fakultas)
        : nama(_nama), umur(_umur), jurusan(_jurusan), fakultas(_fakultas) {}

    virtual void displayStatus() const = 0;

    string getNama() const {
        return nama;
    }

    int getUmur() const {
        return umur;
    }

    string getJurusan() const {
        return jurusan;
    }

    string getFakultas() const {
        return fakultas;
    }
};

class MA : public Mahasiswa {
private:
    string status = "Mahasiswa Aktif";
public:
    MA(string _nama, int _umur, string _jurusan, string _fakultas)
        : Mahasiswa(_nama, _umur, _jurusan, _fakultas) {}

    void displayStatus() const override {
        cout << "Status: " << status << endl;
    }
};

class Alumni : public Mahasiswa {
private:
    string status = "Alumni";
public:
    Alumni(string _nama, int _umur, string _jurusan, string _fakultas)
        : Mahasiswa(_nama, _umur, _jurusan, _fakultas) {}

    void displayStatus() const override {
        cout << "Status: " << status << endl;
    }
};

int main() {
    const int MAHASISWA = 5;
    Mahasiswa* daftar[MAHASISWA];

    for (int i = 0; i < MAHASISWA; ++i) {
        string nama, jurusan, fakultas;
        int umur;
        char status;

        cout << "Masukkan nama: ";
        getline(cin, nama);
        cout << "Masukkan umur: ";
        cin >> umur;
        cin.ignore(); 
        cout << "Masukkan jurusan: ";
        getline(cin, jurusan);
        cout << "Masukkan fakultas: ";
        getline(cin, fakultas);
        cout << "Masukkan status (A untuk Alumni, M untuk Mahasiswa Aktif): ";
        cin >> status;
        cin.ignore();

        if (status == 'A' || status == 'a') {
            daftar[i] = new Alumni(nama, umur, jurusan, fakultas);
        } else if (status == 'M' || status == 'm') {
            daftar[i] = new MA(nama, umur, jurusan, fakultas);
        } else {
            cout << "Status tidak valid." << endl;
            --i;
        }
    }

    cout << "\nDaftar Mahasiswa\n";
    for (int i = 0; i < MAHASISWA; ++i) {
        cout << "Nama: " << daftarMahasiswa[i]->getNama() << endl;
        cout << "Umur: " << daftarMahasiswa[i]->getUmur() << endl;
        cout << "Jurusan: " << daftarMahasiswa[i]->getJurusan() << endl;
        cout << "Fakultas: " << daftarMahasiswa[i]->getFakultas() << endl;
        daftarMahasiswa[i]->displayStatus(); 
        cout << endl;
    }

    for (int i = 0; i < MAHASISWA; ++i) {
        delete daftar[i];
    }

    return 0;
}
