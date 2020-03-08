#include "Food.h"

string Food::getName() const {
    return name;
}

int Food::calories() const {
    return carbs * 4 + protein * 4 + fat * 9;
}

bool Food::setName(string _name) {
    name = _name;
    return true;
}
