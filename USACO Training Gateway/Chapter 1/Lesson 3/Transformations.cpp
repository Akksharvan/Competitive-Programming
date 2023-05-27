/*
ID: akkshar1
TASK: transform
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool squareCompare(char squareOne[10][10], char squareTwo[10][10], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (squareOne[i][j] != squareTwo[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ifstream fin;
    fin.open("transform.in");

    int N;
    int transformation = 7;

    fin >> N;

    char originalSquare[10][10];
    char transformedSquare[10][10];

    for (int i = 0; i < N; i++) {
        string currentLine;
        fin >> currentLine;

        for (int j = 0; j < N; j++) {
            originalSquare[i][j] = currentLine[j];
        }
    }

    for (int i = 0; i < N; i++) {
        string currentLine;
        fin >> currentLine;

        for (int j = 0; j < N; j++) {
            transformedSquare[i][j] = currentLine[j];
        }
    }

    fin.close();

    char caseOneSquare[10][10];
    char caseTwoSquare[10][10];
    char caseThreeSquare[10][10];

    char caseFourSquare[10][10];

    char caseFiveDashOneSquare[10][10];
    char caseFiveDashTwoSquare[10][10];
    char caseFiveDashThreeSquare[10][10];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            caseOneSquare[j][N - 1 - i] = originalSquare[i][j];
            caseTwoSquare[N - 1 - i][N - 1 - j] = originalSquare[i][j];
            caseThreeSquare[N - 1 - j][i] = originalSquare[i][j];

            caseFourSquare[i][N - 1 - j] = originalSquare[i][j];

            caseFiveDashOneSquare[i][N - 1 - j] = originalSquare[i][j];
            caseFiveDashTwoSquare[N - 1 - j][N - 1 - i] = originalSquare[i][j];
            caseFiveDashThreeSquare[N - 1 - i][j] = originalSquare[i][j];
        }
    }

    if (squareCompare(transformedSquare, originalSquare, N)) {
        transformation = 6;
    }
    
    if (squareCompare(transformedSquare, caseFiveDashOneSquare, N) || squareCompare(transformedSquare, caseFiveDashTwoSquare, N) || squareCompare(transformedSquare, caseFiveDashThreeSquare, N)) {
        transformation = 5;
    }

    if (squareCompare(transformedSquare, caseFourSquare, N)) {
        transformation = 4;
    }

    if (squareCompare(transformedSquare, caseThreeSquare, N)) {
        transformation = 3;
    }

    if (squareCompare(transformedSquare, caseTwoSquare, N)) {
        transformation = 2;
    }

    if (squareCompare(transformedSquare, caseOneSquare, N)) {
        transformation = 1;
    }

    ofstream fout;
    fout.open("transform.out");

    fout << transformation << endl;

    fout.close();
    return 0;
}