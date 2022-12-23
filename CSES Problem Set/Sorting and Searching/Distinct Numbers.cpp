#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> distinctNumbers;
    long long int distinctNumbersCounter = 0;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        distinctNumbers.insert(number);
    }

    for (auto &distinctNumber : distinctNumbers) {
        if (distinctNumber) {
            distinctNumbersCounter++;
        }
    }

    cout << distinctNumbersCounter << "\n";

    return 0;
}