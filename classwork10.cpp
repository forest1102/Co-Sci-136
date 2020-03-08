#include "Recipe.h"

#include <iostream>

using namespace std;

int main() {
    Food food1, food2("Apple", 100, 100, 100);
    Food foods[] = { food1, food2 };
    Recipe recipe(foods, "Apples", 2);

    cout << recipe.calories() << endl;
    return 0;
}
