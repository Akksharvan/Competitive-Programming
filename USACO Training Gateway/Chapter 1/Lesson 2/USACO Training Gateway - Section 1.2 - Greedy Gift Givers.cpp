/*
ID: akkshar1
TASK: gift1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {
    public:
        string name;
        int bankBalance = 0;

        Person() {
            name = "Anonymous";
        }

        Person(string name) {
            this -> name = name;
        }
};

int main() {
    ifstream fin;
    fin.open("gift1.in");

    int NP;
    fin >> NP;

    Person personArray[NP];
    Person* personArrayPointer[NP];

    for (int i = 0; i < NP; i++) {
        string name;
        fin >> name;

        personArray[i] = Person(name);
        personArrayPointer[i] = &personArray[i];
    }

    string name;

    while(fin >> name) {
        int giftMoney;
        int NG;
        int individualGiftMoney;
        int remainder;

        fin >> giftMoney >> NG;

        if (NG != 0) {
            individualGiftMoney = giftMoney / NG;
            remainder = giftMoney % NG;
        }
        else {
            individualGiftMoney = 0;
            remainder = 0;
        }

        for (int i = 0; i < NP; i++) {
            if (name == personArrayPointer[i] -> name) {
                personArrayPointer[i] -> bankBalance -= giftMoney;
                personArrayPointer[i] -> bankBalance += remainder;
            }
        }

        for (int i = 0; i < NG; i++) {
            string currentName;
            fin >> currentName;

            for (int index = 0; index < NP; index++) {
                if (currentName == personArrayPointer[index] -> name) {
                    personArrayPointer[index] -> bankBalance += individualGiftMoney;
                }
            }
        }
    }

    fin.close();

    ofstream fout;
    fout.open("gift1.out");

    for (int i = 0; i < NP; i++) {
        fout << personArray[i].name << " " << personArray[i].bankBalance << endl;
    }
    
    fout.close();
    return 0;
}