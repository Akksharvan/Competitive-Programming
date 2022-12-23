/*
ID: akkshar1
TASK: milk2
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin;
    fin.open("milk2.in");

    int N;
    int minimum;
    int maximum;
    int longestIntervalDuration = 0;
    int longestIdleDuration = 0;

    fin >> N;
    
    vector<bool> intervalVector = {false};
    intervalVector.reserve(1000000);

    for (int i = 0; i < N; i++) {
        int currentStart;
        int currentEnd;
        
        fin >> currentStart >> currentEnd;

        for (int i = currentStart; i < currentEnd; i++) {
            intervalVector[i] = true;
        }

        if (i == 0) {
            minimum = currentStart;
            maximum = currentEnd;
        }

        if (currentStart < minimum) {
            minimum = currentStart;
        }

        if (currentEnd > maximum) {
            maximum = currentEnd;
        }
    }

    fin.close();

    int trueCounter = 0;
    int falseCounter = 0;

    for (int i = minimum; i < maximum; i++) {
        if (intervalVector[i]) {
            if (falseCounter > longestIdleDuration) {
                longestIdleDuration = falseCounter;
            }

            trueCounter++;
            falseCounter = 0;
        }
        else {
            if (trueCounter > longestIntervalDuration) {
                longestIntervalDuration = trueCounter;
            }

            falseCounter++;
            trueCounter = 0;
        }
    }

    if (trueCounter > longestIntervalDuration) {
        longestIntervalDuration = trueCounter;
    }

    if (falseCounter > longestIdleDuration) {
        longestIdleDuration = falseCounter;
    }

    ofstream fout;
    fout.open("milk2.out");

    fout << longestIntervalDuration << " " << longestIdleDuration << endl;
    
    fout.close();
    return 0;
}