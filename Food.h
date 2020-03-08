#include <string>
using namespace std;

class Food {
private:
    string name;
    int carbs;
    int protein;
    int fat;

public:
    Food(const string& _name, int _carbs, int _protein, int _fat)
        : name(_name), carbs(_carbs), protein(_protein), fat(_fat) { }

    Food()
        : name("No Name"), carbs(0), protein(0), fat(0) { }

    string getName() const;
    int calories() const;

    bool setName(string _name);
};
