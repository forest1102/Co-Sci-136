#include <iostream>
#include "Food.h"

using namespace std;

int main() {
    Food food1("Apple", 12, 4, 5);

    cout << food1.getName() << endl;
    cout << food1.calories() << endl;

    food1.setName("Pizza");

    Food food2;

    cout << food2.getName() << endl;
}
