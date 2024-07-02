#include <iostream>
#include <vector>
using namespace std;

class DHTable {
private:
    vector<int> table;
    int size;
    int count;

    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        return 7 - (key % 7);
    }

public:
    DHTable(int tSize) : size(tSize), count(0) {
        table.resize(size, -1);
    }

    void insert(int key) {
        if (count == size) {
            cout << "Tabel penuh" << endl;
            return;
        }

        int index = hash1(key);
        int step = hash2(key);

        while (table[index] != -1) {
            index = (index + step) % size;
        }

        table[index] = key;
        count++;
    }

    bool search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int sIndex = index;

        do {
            if (table[index] == key) {
                return true;
            }
            if (table[index] == -1) {
                return false;
            }
            index = (index + step) % size;
        } while (index != sIndex);

        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1) {
                cout << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    DHTable ht(11);

    ht.insert(10);
    ht.insert(22);
    ht.insert(31);
    ht.insert(4);
    ht.insert(15);
    ht.insert(28);
    ht.insert(17);
    ht.insert(88);
    ht.insert(59);

    cout << "Isi tabel hash:" << endl;
    ht.display();

    int sKey = 22;
    if (ht.search(sKey)) {
        cout << sKey << " ditemukan dalam tabel" << endl;
    } else {
        cout << sKey << " tidak ditemukan dalam tabel" << endl;
    }

    return 0;
}


