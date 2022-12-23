/*
ID: akkshar1
TASK: dualpal
LANG: C++                 
*/

#include <iostream>
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

    return convertedNumber;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    int N, S;
    cin >> N >> S;

    S++;
    vector<int> palindromic_numbers;
    int size = palindromic_numbers.size();

    while(size < N) {
        int palindrome_counter = 0;

        for (int i = 2; i <= 10; i++) {
            if (i != 10) {
                string baseNumber = convertToBase(S, i);
				string reversedNumber = baseNumber;
				reverse(reversedNumber.begin(), reversedNumber.end());
				
                if (baseNumber == reversedNumber) {
                    palindrome_counter++;
                    if (palindrome_counter >= 2) {
                        break;
                    }
                }
            }
            else {
                string baseNumber = to_string(S);
				string reversedNumber = baseNumber;
				reverse(reversedNumber.begin(), reversedNumber.end());

                if (baseNumber == reversedNumber) {
                    palindrome_counter++;
                }
            }
        }

        if (palindrome_counter >= 2) {
            palindromic_numbers.push_back(S);
        }

        size = palindromic_numbers.size();
        S++;
    }

    for (const int& palindromic_number : palindromic_numbers) {
        cout << palindromic_number << "\n";
    }
    
    return 0;
}