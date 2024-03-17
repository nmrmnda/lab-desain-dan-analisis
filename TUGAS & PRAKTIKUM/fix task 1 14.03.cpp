#include <iostream>
using namespace std;

int data[10];
int n;

void tampil(int i)
{
	cout << "\n Proses Sorting \n";
    for (int j = 0; j < n; j++) {
        cout << "[" << data[j] << "] ";
    }
    cout << i << ": ";
    for (int j = 0; j < n; j++) {
        cout << data[j] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Masukan Jumlah Array = ";
    cin >> n;

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Masukan Data Ke-" << i << " = ";
        cin >> data[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int t;
                t = data[j];
                data[j] = data[j + 1];
                data[j + 1] = t;
            }
        }
        tampil(i);
    }

    cout << "\n Hasil Akhir : ";
    for (int i = 0; i < n; i++)
    {
        cout << data [i];
    }
    cout<<endl;
    return 0;
}
