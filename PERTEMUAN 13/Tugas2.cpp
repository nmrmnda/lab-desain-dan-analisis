#include <iostream>
#include <vector>
using namespace std;

int hFunction(int key, int tSize) {
  return key % tSize;
}

struct HTable {
  vector<int> table;
  int size;


  HTable(int size) {
    this->size = size;
    table.resize(size, -1); 
  }

  void insert(int key) {
    int index = hFunction(key, size);

    while (table[index] != -1) {
      index = (index + 1) % size;
    }

    table[index] = key;
  }

  bool search(int key) {
    int index = hFunction(key, size);

    while (table[index] != -1) {
      if (table[index] == key) {
        return true; 
      }
      index = (index + 1) % size;
    }

    return false; 
  }

  void display() {
    for (int i = 0; i < size; i++) {
      cout << i << " --> ";
      if (table[i] == -1) {
        cout << "Kosong" << endl;
      } else {
        cout << table[i] << endl;
      }
    }
  }
};

int main() {
  int tSize, numElements, key;

  cout << "Masukkan ukuran tabel hash: ";
  cin >> tSize;

  cout << "Masukkan jumlah elemen yang akan disisipkan: ";
  cin >> numElements;

  HTable hTable(tSize);

  cout << "Masukkan " << numElements << " elemen:" << endl;
  for (int i = 0; i < numElements; i++) {
    cin >> key;
    hTable.insert(key);
  }

  cout << "\nIsi Tabel Hash:" << endl;
  hTable.display();

  cout << "\nMasukkan elemen yang ingin dicari dalam tabel hash: ";
  cin >> key;

  if (hTable.search(key)) {
    cout << key << " ditemukan dalam tabel hash." << endl;
  } else {
    cout << key << " tidak ditemukan dalam tabel hash." << endl;
  }

  return 0;
}
