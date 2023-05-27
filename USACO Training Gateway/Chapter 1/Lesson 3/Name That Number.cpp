/*
ID: akkshar1
TASK: namenum
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin;
    fin.open("namenum.in");

    int64_t brandNumber;
    fin >> brandNumber;

    fin.close();

    int64_t tempBrandNumber = brandNumber;
    int64_t brandNumberSize = 0ll;

    while (tempBrandNumber != 0) {
        brandNumberSize++;
        tempBrandNumber /= 10;
    }

    int64_t number;
    string name;

    map<string, int> conversionChart = { {"A", 2}, {"B", 2}, {"C", 2}, {"D", 3}, {"E", 3}, {"F", 3}, {"G", 4}, {"H", 4}, {"I", 4}, {"J", 5}, {"K", 5}, {"L", 5}, {"M", 6}, {"N", 6}, {"O", 6}, {"P", 7}, {"R", 7}, {"S", 7}, {"T", 8}, {"U", 8}, {"V", 8}, {"W", 9}, {"X", 9}, {"Y", 9} };
    vector<string> acceptableNames;

    ifstream din;
    din.open("dict.txt");

    while (din >> name) {
        number = 0ll;

        for (int i = 0; i < brandNumberSize; i++) {
            number *= 10;
            number += conversionChart[string(1, name[i])];
        }

        if (number == brandNumber && name.length() == brandNumberSize) {
            acceptableNames.push_back(name);
        }
    }

    din.close();

    sort(acceptableNames.begin(), acceptableNames.end());

    ofstream fout;
    fout.open("namenum.out");

    for (int i = 0; i < acceptableNames.size(); i++) {
        fout << acceptableNames[i] << endl;
    }

    if (acceptableNames.size() == 0) {
        fout << "NONE" << endl;
    }

    fout.close();

    return 0;
}