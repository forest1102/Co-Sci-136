#include <iostream>
#include <iterator>
#include <random>

using namespace std;

void show(int a[], int n) {
    copy(a, a + n, ostream_iterator<int>(cout, " "));
    cout << endl;
}

void fill(int a[], int size, int val) {
    for (int i = 0; i < size; ++i) {
        a[i] = val;
    }
}

int main() {
    const int size = 12;
    int array[size];

    show(array, size);
    fill(array, size, 13);
    show(array, size);
}
