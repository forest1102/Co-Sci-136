#include <iostream>
#include <string>
#include <random>

using namespace std;

string randomString(default_random_engine &e, uniform_int_distribution<int> &uchrs,
  uniform_int_distribution<int> &ulens) {
    int rlength = ulens(e);
    int rchr    = uchrs(e);
    string rstring(rlength, rchr);

    return rstring;
}

int main() {
    default_random_engine e;

    uniform_int_distribution<int> uchrs((int) 'A', (int) 'Z');
    uniform_int_distribution<int> ulens(1, 32);
    const int nStrings = 16;

    for (int k = 1; k <= nStrings; ++k)
        cout << randomString(e, uchrs, ulens) << endl;
}
