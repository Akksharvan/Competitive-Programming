/*
ID: akkshar1
TASK: ride
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int rideMod47(string word) {
    int size = word.length();
    int product = 1;
    int remainder;

    map<string, int> conversions;
    conversions.insert(pair<string, int>("A", 1));
    conversions.insert(pair<string, int>("B", 2));
    conversions.insert(pair<string, int>("C", 3));
    conversions.insert(pair<string, int>("D", 4));
    conversions.insert(pair<string, int>("E", 5));
    conversions.insert(pair<string, int>("F", 6));
    conversions.insert(pair<string, int>("G", 7));
    conversions.insert(pair<string, int>("H", 8));
    conversions.insert(pair<string, int>("I", 9));
    conversions.insert(pair<string, int>("J", 10));
    conversions.insert(pair<string, int>("K", 11));
    conversions.insert(pair<string, int>("L", 12));
    conversions.insert(pair<string, int>("M", 13));
    conversions.insert(pair<string, int>("N", 14));
    conversions.insert(pair<string, int>("O", 15));
    conversions.insert(pair<string, int>("P", 16));
    conversions.insert(pair<string, int>("Q", 17));
    conversions.insert(pair<string, int>("R", 18));
    conversions.insert(pair<string, int>("S", 19));
    conversions.insert(pair<string, int>("T", 20));
    conversions.insert(pair<string, int>("U", 21));
    conversions.insert(pair<string, int>("V", 22));
    conversions.insert(pair<string, int>("W", 23));
    conversions.insert(pair<string, int>("X", 24));
    conversions.insert(pair<string, int>("Y", 25));
    conversions.insert(pair<string, int>("Z", 26));

    for (int i = 0; i < size; i++) {
        string index = word.substr(i, 1);
        product = product * conversions[index];
    }

    remainder = product % 47;
    return remainder;
}

int main() {
    ifstream fin;
    
    fin.open("ride.in");
    string a, b;

    getline(fin, a);
    getline(fin, b);

    fin.close();

    int groupRemainder = rideMod47(a);
    int cometRemainder = rideMod47(b);


    ofstream fout;
    fout.open("ride.out");

    if (groupRemainder == cometRemainder) {
        fout << "GO" << endl;
    }
    else {
        fout << "STAY" << endl;
    }

    return 0;
}