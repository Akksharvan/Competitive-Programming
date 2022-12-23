#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int minimalDifference = 1e9ll;
    bool minDifZero = false;

    int n;
    vector<int> apples(n);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> apples[n];
    }

    int index = 1;

    while (!minDifZero) {
        if (index == n) {
            break;
        }

        long long int group1 = 0ll;
        long long int group2 = 0ll;

        for (int i = 0; i < index; i++) {
            group1 += apples[i];
        }

        for (int i = index; i < n; i++) {
            group2 += apples[i];
        }

        minimalDifference = min(minimalDifference, max(group1 - group2, group2 - group1));

        if (minimalDifference == 0) {
            minDifZero = true;
        }

        index++;
    }

    cout << minimalDifference << "\n";

    return 0;
}