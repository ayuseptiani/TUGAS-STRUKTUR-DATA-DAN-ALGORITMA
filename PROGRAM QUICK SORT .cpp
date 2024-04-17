#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partisi(int arr[], int rendah, int tinggi) {
    int pivot = arr[(rendah + tinggi) / 2];
    int i = rendah;
    int j = tinggi;

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tukar(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(int arr[], int rendah, int tinggi) {
    if (rendah < tinggi) {
        int pi = partisi(arr, rendah, tinggi);
        quicksort(arr, rendah, pi - 1);
        quicksort(arr, pi, tinggi);
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array sebelum diurutkan:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1);

    cout << "Array setelah diurutkan:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
