#include "Food.h"

class Recipe {
private:
    Food * ingredients;
    string name;
    int n;
public:
    Recipe(Food _ingredients[], const string& _name, int _n);

    Recipe()
        : ingredients(nullptr), name("No Name"), n(0) { }

    int calories() const;

    ~Recipe();
};
