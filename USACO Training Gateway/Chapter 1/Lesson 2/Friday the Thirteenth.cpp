/*
ID: akkshar1
TASK: friday
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

void thirteenthCalculator(map<int, int> * m, int year, int dayOne, int years) {
    bool is_leap_year;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        is_leap_year = true;
    }
    else {
        is_leap_year = false;
    }

    map<int, int> thirteenths;
    thirteenths.insert(pair<int, int>(0, 12));
    thirteenths.insert(pair<int, int>(1, 31));
    thirteenths.insert(pair<int, int>(2, 28));
    thirteenths.insert(pair<int, int>(3, 31));
    thirteenths.insert(pair<int, int>(4, 30));
    thirteenths.insert(pair<int, int>(5, 31));
    thirteenths.insert(pair<int, int>(6, 30));
    thirteenths.insert(pair<int, int>(7, 31));
    thirteenths.insert(pair<int, int>(8, 31));
    thirteenths.insert(pair<int, int>(9, 30));
    thirteenths.insert(pair<int, int>(10, 31));
    thirteenths.insert(pair<int, int>(11, 30));

    if (is_leap_year) {
        thirteenths[2] = 29;
    }

    int currentDay = dayOne;
    
    for (int i = 0; i < 12; i++) {
        currentDay = (currentDay + thirteenths[i]) % 7;
        (*m)[currentDay] += 1;
    }

    int nextDayOne;

    if (is_leap_year) {
        nextDayOne = (dayOne + 366) % 7;
    }
    else {
        nextDayOne = (dayOne + 365) % 7;
    }

    if (year != (1900 + (years - 1))) {
        thirteenthCalculator(m, year + 1, nextDayOne, years);
    }
}

int main() {
    ifstream fin;
    fin.open("friday.in");

    int years;
    fin >> years;

    fin.close();

    map<int, int> days;
    days.insert(pair<int, int>(0, 0));
    days.insert(pair<int, int>(1, 0));
    days.insert(pair<int, int>(2, 0));
    days.insert(pair<int, int>(3, 0));
    days.insert(pair<int, int>(4, 0));
    days.insert(pair<int, int>(5, 0));
    days.insert(pair<int, int>(6, 0));

    map<int, int> *daysPointer = &days;

    thirteenthCalculator(daysPointer, 1900, 2, years);

    ofstream fout;
    fout.open("friday.out");

    for (int i = 0; i < 7; i++) {
        if (i != 6) {
            fout << days[i] << " ";
        }
        else {
            fout << days[i] << endl;
        }
    }

    fout.close();

    return 0;
}