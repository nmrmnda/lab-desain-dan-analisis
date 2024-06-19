#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

class Graf {
private:
    int jumlahSimpul;
    vector<vector<int>> daftarAdjasi;

public:
    Graf(int simpul);
    void tambahkanTepi(int src, int dest);
    void cetakGraf();
};

Graf::Graf(int simpul) {
    jumlahSimpul = simpul;
    daftarAdjasi.resize(simpul);
}

void Graf::tambahkanTepi(int src, int dest) {
    daftarAdjasi[src].push_back(dest);
}

void Graf::cetakGraf() {
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Daftar tetangga simpul " << i << " : ";
        for (size_t j = 0; j < daftarAdjasi[i].size(); j++) {
            cout << daftarAdjasi[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Representasi graf menggunakan daftar adjasi : " << endl;
    int jumlahSimpul = 4; 
    Graf graf(jumlahSimpul);

    graf.tambahkanTepi(0, 1);
    graf.tambahkanTepi(0, 2);
    graf.tambahkanTepi(1, 2);
    graf.tambahkanTepi(2, 0);
    graf.tambahkanTepi(2, 3);
    graf.tambahkanTepi(3, 3);

    // Cetak graf
    graf.cetakGraf();

    return 0;
}

