#include <iostream>
#include <iterator>

using namespace std;

void show(int a[], int n) {
    copy(a, a + n, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int linearSearch(int a[], int n, int val) {
    int k = 0;

    while (k < n && a[k] != val)
        k++;

    return ((k == n) ? -1 : k);
}

bool insertAt(int a[], int& size, int capacity, int p, int val) {
    if (p < 0 || p > size || size == capacity) return false;

    for (int i = size; i > p; i--) {
        a[i] = a[i - 1];
    }

    a[p] = val;
    size++;

    return true;
}

bool append(int a[], int& population, int capacity, int val) {
    return insertAt(a, population, capacity, population, val);
}

bool deleteAt(int a[], int& population, int p) {
    if (p < 0 || p >= population) return false;

    for (int i = p; i < population - 1; i++) {
        a[i] = a[i + 1];
    }

    population--;

    return true;
}

bool deleteItem(int a[], int &population, int val) {
    int p = linearSearch(a, population, val);

    return deleteAt(a, population, p);
}

void sort(int a[], int population) {
    for (int sorted = -1; sorted < population - 1; sorted++)
        for (int unsorted = population - 1; unsorted > sorted; unsorted--)
            if (a[unsorted] < a[unsorted - 1]) {
                int temp = a[unsorted];
                a[unsorted]     = a[unsorted - 1];
                a[unsorted - 1] = temp;
            }
}

int main() {
    const int capacity  = 12;
    int array[capacity] = { 45, 54, 13, 21, 18, 95, 14, 21, 72, 27, 88, 19 };

    show(array, capacity);

    cout << linearSearch(array, capacity, array[0]) << endl;
    cout << linearSearch(array, capacity, array[capacity - 1]) << endl;
    cout << linearSearch(array, capacity, array[capacity / 2]) << endl;
    cout << linearSearch(array, capacity, 99) << endl;

    int array2[capacity] = { 0 };
    int population2      = 0;

    insertAt(array2, population2, capacity, 2, 45);
    cout << population2 << endl;
    insertAt(array2, population2, capacity, 0, 45);
    cout << population2 << endl;
    insertAt(array2, population2, capacity, 0, 54);
    cout << population2 << endl;
    show(array2, population2);

    int population = capacity;

    show(array, population);
    deleteAt(array, population, 0);
    show(array, population);
    deleteAt(array, population, population - 1);
    show(array, population);
    deleteAt(array, population, population / 2);
    show(array, population);

    int array3[capacity] = { 45, 54, 13, 21, 18, 95, 14, 21, 72, 27, 88, 19 };

    show(array3, capacity);
    sort(array3, capacity);
    show(array3, capacity);
}
