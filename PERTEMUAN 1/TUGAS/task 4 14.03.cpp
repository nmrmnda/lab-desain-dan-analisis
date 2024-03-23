#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Book {
    string title;
};

bool compareBooks(const Book &a, const Book &b) {
    return a.title < b.title;
}

int main() {
    int n;
    cout << "Jumlah buku yang di input : ";
    cin >> n;
    cin.ignore(); // Menghapus karakter newline dari buffer
    Book *books = new Book[n];
    for (int i = 0; i < n; i++) {
        cout << "\n Masukkan judul buku " << i+1 << " : ";
        getline(cin, books[i].title);
    }
    sort(books, books+n, compareBooks);
    cout << "\n Pengurutan buku : \n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << books[i].title << endl;
    }
    delete[] books; // Menghapus memori yang dialokasikan
    return 0;
}

