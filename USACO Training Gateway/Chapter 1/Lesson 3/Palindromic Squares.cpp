/*
ID: akkshar1
TASK: palsquare
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

string convertToBase(int base10Number, int base) {
    vector<string> convertedVector;
    string convertedNumber;
    map<int, string> conversionChart = { {0, "0"}, {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}, {10, "A"}, {11, "B"}, {12, "C"}, {13, "D"}, {14, "E"}, {15, "F"}, {16, "G"}, {17, "H"}, {18, "I"}, {19, "J"} };
    bool firstRun = true;

    cout <<  "Original Number:" << base10Number << " Base:" << base;

    while (base10Number != 0) {
        int digit = base10Number % base;
        base10Number /= base;

        string stringDigit = conversionChart[digit];
        convertedVector.push_back(stringDigit);
    }

    reverse(convertedVector.begin(), convertedVector.end());

    for (int i = 0; i < convertedVector.size(); i++) {
        if (i == 0) {
            convertedNumber = convertedVector[i];
        }
        else {
            convertedNumber += convertedVector[i];
        }
    }

    cout <<" Converted Number:" + convertedNumber << endl;
    return convertedNumber;
}

int main() {
    ifstream fin;
    fin.open("palsquare.in");

    int base;
    fin >> base;

    fin.close();

    queue<int> palindromes;

    for (int i = 1; i <= 300; i++) {
        int iSquared = i * i;
        string stringNumberSquaredBased = convertToBase(iSquared, base);
        string stringNumberSquaredBasedReversed;

        for (int j = stringNumberSquaredBased.length() - 1; j >= 0; j--) {
            if (j == stringNumberSquaredBased.length() - 1) {
                stringNumberSquaredBasedReversed = stringNumberSquaredBased[j];
            }
            else {
                stringNumberSquaredBasedReversed += stringNumberSquaredBased[j];
            }
        }

        if (stringNumberSquaredBased == stringNumberSquaredBasedReversed) {
            palindromes.push(i);
        }
    }

    ofstream fout;
    fout.open("palsquare.out");

    while (!palindromes.empty()) {
        int firstDigit = palindromes.front();
        int firstDigitSquared = firstDigit * firstDigit;

        palindromes.pop();

        string number = convertToBase(firstDigit, base);
        string numberSquared = convertToBase(firstDigitSquared, base);

        fout << number << " " << numberSquared << endl;
    }

    fout.close();
    return 0;
}