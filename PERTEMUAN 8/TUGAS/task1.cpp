#include <iostream>
using namespace std;

const int MAX = 5; 

class Queue {
    private:
        string name[MAX];
        int front, rear;

    public:
        Queue() {
            front = -1;
            rear = -1;
        }

        bool isFull() {
            return (rear == MAX - 1);
        }

        bool isEmpty() {
            return (front == -1 || front > rear);
        }

        void enqueue(string n) {
            if (isFull()) {
                cout << "Penonton bioskop sudah penuh!\n";
                return;
            }
            if (front == -1) front = 0;
            name[++rear] = n;
            cout <<"Penonton "<< n << " Masuk dalam list.";
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "Tidak ada penonton yang menukar tiket!\n";
                return;
            }
            cout << "Memberi " << name[front++] << " tiketnya\n";
            if (front > rear) {
                front = rear = -1;
            }
        }

        void tampil() {
            if (isEmpty()) {
                cout << "Tidak ada penonton didalam list. \n";
                return;
            }
            cout << "List penonton : \n";
            for (int i = front; i <= rear; i++) {
                cout << name[i] << endl;
            }
        }

        void end() {
            cout << "End from system\n";
        }
};

int main() {
    Queue q;
    int p;
    string name;

    do {
        cout << "\nANTRIAN LOKET TIKET" << endl;
        cout << "1. Tambah penonton" << endl;
        cout << "2. Melayani customer" << endl;
        cout << "3. Tampilkan list penonton" << endl;
        cout << "4. Exit sistem" << endl;
        cout << "Pilih Opsi : ";
        cin >> p;
        cin.ignore(); 

        if (p == 1) {
            cout << "Masukkan nama : ";
            getline(cin, name);
            q.enqueue(name);
        } else if (p == 2) {
            q.dequeue();
        } else if (p == 3) {
            q.tampil();
        } else if (p == 4) {
            q.end();
        } else {
            cout << "Pilihan tidak valid, coba lagi.\n";
        }
    } while (p != 4);

    return 0;
}
