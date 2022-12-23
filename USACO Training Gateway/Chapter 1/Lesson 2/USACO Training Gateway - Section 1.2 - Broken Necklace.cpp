/*
ID: akkshar1
TASK: beads
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin;
    fin.open("beads.in");

    int N;
    string necklace;

    fin >> N >> necklace;
    fin.close();

    int maxBeads = 2;

    for (int i = 0; i < N; i++) {
        int directionOneBeads = 0;
        int directionTwoBeads = 0;

        char directionOneBeadsColor;
        char directionTwoBeadsColor;

        for (int j = 0; j < N; j++) {
            if (necklace[j] == 'r' || necklace[j] == 'b') {
                directionOneBeadsColor = necklace[j];
                break;
            }
        }

        for (int j = N - 1; j > 0; j--) {
            if((necklace[j] == 'r' || necklace[j] == 'b') && (necklace[j] != directionOneBeadsColor)) {
                directionTwoBeadsColor = necklace[j];
                break;
            }
        }

        for (int j = 0; j < N; j++) {
            if (necklace[j] == directionOneBeadsColor || necklace[j] == 'w') {
                directionOneBeads += 1;
            }
            else {
                break;
            }
        }

        for (int j = N - 1; j > 0; j--) {
            if (necklace[j] == directionTwoBeadsColor || necklace[j] == 'w') {
                directionTwoBeads += 1;
            }
            else {
                break;
            }
        }

        int totalBeads = directionOneBeads + directionTwoBeads;
        necklace = necklace.substr(1, N) + necklace.substr(0, 1);

        if (totalBeads > maxBeads) {

            if (totalBeads > N) {
                maxBeads = N;
            }
            else {
                maxBeads = totalBeads;
            }
        }
    }

    ofstream fout;
    fout.open("beads.out");

    fout << maxBeads << endl;

    fout.close();
    return 0;
}