#include <iostream>
#include <iterator>
#include <random>
#include <string>

using namespace std;

int main() {
    const int PLAYER_NUM     = 5;
    const int FACES          = 6;
    const int MAX_POINTS     = 50;
    int scores[PLAYER_NUM]   = { 0 };
    string names[PLAYER_NUM] = { "Jed", "Ned", "Ted", "Zed", "Red" };

    default_random_engine e;
    uniform_int_distribution<int> ud(1, FACES);
    uniform_int_distribution<int> up(1, PLAYER_NUM);

    e.seed((unsigned int) time(nullptr));

    int pIndex     = up(e);
    bool last_turn = false;

    do {
        pIndex = (pIndex + 1) % PLAYER_NUM;

        int die = ud(e);
        scores[pIndex] += die;

        cout << names[pIndex] << " rolled " << die
             << " with " << scores[pIndex] << " points" << endl;

        if (scores[pIndex] > MAX_POINTS) {
            scores[pIndex] /= 2;
            cout << "\tbut lose " << scores[pIndex] << " points" << endl;
        } else if (scores[pIndex] == MAX_POINTS) {
            last_turn = true;
        }
    } while (!last_turn && pIndex < PLAYER_NUM);

    for (int i = 0; i < PLAYER_NUM; i++) {
        if (scores[i] == MAX_POINTS) {
            cout << names[i] << " won!" << endl;
        }
    }
}
