#include "Recipe.h"

Recipe::Recipe(Food _ingredients[], const string& _name, int _n) {
    name        = _name;
    n           = _n;
    ingredients = new Food [_n];

    for (int i = 0; i < _n; i++) {
        ingredients[i] = _ingredients[i];
    }
}

int Recipe::calories() const {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += ingredients[i].calories();
    }

    return total;
}

Recipe::~Recipe() {
    delete[] ingredients;
    ingredients = nullptr;
}
