#include <iostream>
#include <iterator>
#include <random>
#include <string>

using namespace std;

int main() {
    const int PLAYER_NUM     = 4;
    const int FACES          = 6;
    const int MAX_POINTS     = 50;
    int scores[PLAYER_NUM]   = { 0 };
    string names[PLAYER_NUM] = { "Jed", "Ned", "Ted", "Zed" };

    default_random_engine e;
    uniform_int_distribution<int> ud(1, FACES);
    uniform_int_distribution<int> up(1, PLAYER_NUM);
    int seed = 12;

    e.seed(seed);

    int pIndex = up(e);
    do {
        pIndex = (pIndex + 1) % PLAYER_NUM;

        int die = ud(e);
        scores[pIndex] += die;

        cout << names[pIndex] << " rolled " << die
             << " with " << scores[pIndex] << " points" << endl;

        if (scores[pIndex] > MAX_POINTS) {
            scores[pIndex] /= 2;
            cout << "\tbut lose " << scores[pIndex] << " points" << endl;
        }
    } while (scores[pIndex] != MAX_POINTS);

    cout << names[pIndex] << " won" << endl;
}
