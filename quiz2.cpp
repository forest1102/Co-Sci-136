/*
 * modify the program to display the largest and smallest elements in
 * the array
 */
// #include "pch.h"
// #include "stdafx.h"

#include <iostream>
#include <iterator>
#include <random>

using namespace std;
int main() {
    const int aSize = 32;
    int numbers[aSize];

    default_random_engine e;
    uniform_int_distribution<int> u(10, 99);
    int seed = 0;
    int max  = 1;
    int min  = 100;

    e.seed(seed);


    for (int i = 0; i < aSize; ++i) {
        int randomNumber = u(e);
        numbers[i] = randomNumber;
        max        = ( randomNumber > max) ? randomNumber : max;
        min        = ( randomNumber < min) ? randomNumber : min;
    }

    copy(numbers, numbers + aSize, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "Min: " << min << endl
         << "Max: " << max << endl;

    return 0;
}
