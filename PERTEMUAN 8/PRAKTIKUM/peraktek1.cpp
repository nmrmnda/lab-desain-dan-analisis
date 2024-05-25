#include <iostream>
using namespace std;

const int MAX = 4; 

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
                cout << "Perut penuh, tidak bisa makan lagi \n";
                return;
            }
            if (front == -1) front = 0;
            name[++rear] = n;
            cout << n << " dimakan!\n";
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "Perut kosong, Lapar!\n";
                return;
            }
            cout << "Memakan " << name[front++] << "\n";
            if (front > rear) {
                front = rear = -1;
            }
        }

        void tampil() {
            if (isEmpty()) {
                cout << "Perut Kosong \n";
                return;
            }
            cout << "Makanan paling baru: \n";
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
        cout << "\nSISTEM PENCERNAAN!" << endl;
        cout << "1. Makan makanan baru" << endl;
        cout << "2. Cerna makanan" << endl;
        cout << "3. Mengingat makanan apa" << endl;
        cout << "4. Exit sistem" << endl;
        cout << "Pilih Opsi: ";
        cin >> p;
        cin.ignore(); 

        if (p == 1) {
            cout << "Masukkan makanan: ";
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
