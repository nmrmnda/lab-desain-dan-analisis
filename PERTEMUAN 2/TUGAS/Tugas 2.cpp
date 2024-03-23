#include <iostream>

using namespace std;

void print(int arr[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i];
        if (i < SIZE - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void merge(int arr[], int low, int mid, int high, int& comparison, int& movement) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    int left[leftSize];
    int right[rightSize];

    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[low + i];
        movement++;
    }
    for (int j = 0; j < rightSize; j++) {
        right[j] = arr[mid + 1 + j];
        movement++;
    }

    int i = 0, j = 0, k = low;

    while (i < leftSize && j < rightSize) {
        comparison++;
        if (left[i] >= right[j]) { 
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
        movement++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
        movement++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
        movement++;
    }
}

void mergeSort(int arr[], int low, int high, int& comparison, int& movement) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        cout << "Memecah List [";
        print(arr + low, mid - low + 1);

        mergeSort(arr, low, mid, comparison, movement);

        cout << "Memecah List [";
        print(arr + mid + 1, high - mid);
        mergeSort(arr, mid + 1, high, comparison, movement);

        cout << "Menggabungkan List [";
        print(arr + low, high - low + 1);
        merge(arr, low, mid, high, comparison, movement);
    }
}

int main() {
    int data[] = {2, 5, 60, 43, 27, 10, 89, 17};
    int SIZE = sizeof(data) / sizeof(data[0]);
    int comparison = 0, movement = 0;

    cout << "Data awal: [";
    print(data, SIZE);

    mergeSort(data, 0, SIZE - 1, comparison, movement);

    cout << "\nData terurut secara descending: [";
    print(data, SIZE);

}
