#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Book {
    string title;
    int rak;
};

int binarySearch(const Book books[], int n, const string& title) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (books[mid].title == title) {
            return mid;
        }

        if (books[mid].title < title) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    const int BOOKS = 4;
    Book library[BOOKS] = {
        {"The maze runner", 1},
        {"Percy Jackson", 2},
        {"Matilda", 3},
        {"Ivanna", 4}
    };

    string search;
    cout<<"Masukkan judul buku yang ingin dicari: ";
    getline(cin, search);

    int index = binarySearch(library, BOOKS, search);

    if (index != -1) {
        cout<< "Buku ditemukan di rak nomor: "<< library[index].rak<<endl;
    } else {
        cout<<"Buku \""<<search<<"\" tidak ditemukan di rak manapun."<<endl;
    }

    return 0;
}
