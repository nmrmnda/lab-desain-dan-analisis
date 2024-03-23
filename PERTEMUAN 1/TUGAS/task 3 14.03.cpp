#include <iostream>
using namespace std;

int main() {
    int t, n, m;
    cout << "Masukkan Jumlah Elemen : ";
    cin >> t;
    int num[t];

    cout << "Masukkan Nilai Elemen : ";
    for (int i = 0; i < t; i++) {
        cin >> num[i];
    }

    cout << "Data Sebelum Sorting : ";
    for (int i = 0; i < t; i++) {
        cout << num[i] << " ";
    }

    for (int i = 0; i < t - 1; i++) {
        n = i;
        for (int j = i + 1; j < t; j++) {
            if (num[j] > num[n]) {
                n = j;
            }
        }

        if (num[i] < num[n]) {
            m = num[i];
            num[i] = num[n];
            num[n] = m;
        }
        
        cout << endl;
        cout << "Iterasi ke- " << i + 1 << " : ";
        for (int a = 0; a < t; a++) {
            cout << num[a] << " ";
        }
    }

    cout << endl;
    cout << "Data Setelah Sorting : ";
    for (int i = 0; i < t; i++) {
        cout << num[i] << " ";
    }

    return 0;
}
