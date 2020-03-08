#include <iostream>
#include <iterator>

using namespace std;

void show(int a[], int n) {
    copy(a, a + n, ostream_iterator<int>(cout, " "));
    cout << endl;
}

void sort(int a[], int population) {
    for (int sorted = -1; sorted < population - 1; sorted++)
        for (int unsorted = population - 1; unsorted > sorted; unsorted--)
            if (a[unsorted] > a[unsorted - 1]) {
                int temp = a[unsorted];
                a[unsorted]     = a[unsorted - 1];
                a[unsorted - 1] = temp;
            }
}

int main() {
    const int capacity  = 12;
    int array[capacity] = { 45, 54, 13, 21, 18, 95, 14, 21, 72, 27, 88, 19 };

    show(array, capacity);
    sort(array, capacity);
    show(array, capacity);
}
