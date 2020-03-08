#include <iostream>
#include <iterator>
#include <random>

using namespace std;

template <typename T> void show(T a[], int n) {
    copy(a, a + n, ostream_iterator<T>(cout, " "));
    cout << endl;
}

template <typename T> int linearSearch(T a[], int n, T val) {
    int k = 0;

    while (k < n && a[k] != val)
        k++;

    return ((k == n) ? -1 : k);
}

template <typename T> bool insertAt(T a[], int& size, int capacity, int p, T val) {
    if (p < 0 || p > size || size == capacity) return false;

    for (int i = size; i > p; i--) {
        a[i] = a[i - 1];
    }

    a[p] = val;
    size++;

    return true;
}

template <typename T> bool append(T a[], int& population, int capacity, T val) {
    return insertAt(a, population, capacity, population, val);
}

template <typename T> bool deleteAt(T a[], int& population, int p) {
    if (p < 0 || p >= population) return false;

    for (int i = p; i < population - 1; i++) {
        a[i] = a[i + 1];
    }

    population--;

    return true;
}

template <typename T> bool deleteItem(T a[], int &population, T val) {
    int p = linearSearch(a, population, val);

    return deleteAt(a, population, p);
}

template <typename T> void sort(T a[], int population) {
    for (int sorted = -1; sorted < population - 1; sorted++)
        for (int unsorted = population - 1; unsorted > sorted; unsorted--)
            if (a[unsorted] < a[unsorted - 1]) {
                T temp = a[unsorted];
                a[unsorted]     = a[unsorted - 1];
                a[unsorted - 1] = temp;
            }
}

string randomString(default_random_engine &e, uniform_int_distribution<int> &uchrs,
  uniform_int_distribution<int> &ulens) {
    int rlength = ulens(e);
    int rchr    = uchrs(e);
    string rstring(rlength, rchr);

    return rstring;
}

int main() {
    int n;

    cout << "Input the number of array" << endl;
    cin >> n;

    string * strArr = new string[n];

    default_random_engine e;
    uniform_int_distribution<int> uchrs((int) 'A', (int) 'Z');
    uniform_int_distribution<int> ulens(1, 32);

    for (int i = 0; i < n; i++) {
        strArr[i] = randomString(e, uchrs, ulens);
    }

    show(strArr, n);

    cout << linearSearch(strArr, n, strArr[0]) << endl;
    cout << linearSearch(strArr, n, strArr[n - 1]) << endl;
    cout << linearSearch(strArr, n, strArr[n / 2]) << endl;
    cout << linearSearch(strArr, n, string("Apple")) << endl;


    int population = n;

    show(strArr, population);
    deleteAt(strArr, population, 0);
    show(strArr, population);
    deleteAt(strArr, population, population - 1);
    show(strArr, population);
    deleteAt(strArr, population, population / 2);
    show(strArr, population);

    int population2 = population;
    insertAt(strArr, population2, n, 2, string("Apple"));
    cout << population2 << endl;
    insertAt(strArr, population2, n, 0, randomString(e, uchrs, ulens));
    cout << population2 << endl;
    show(strArr, population2);

    delete[] strArr;
}
