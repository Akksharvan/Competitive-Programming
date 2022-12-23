#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    n *= 2;

    vector<int> weights;

    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        weights.push_back(weight);
    }

    sort(weights.begin(), weights.end());
    int minInstability = INT32_MAX;

    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> newWeights;

            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    newWeights.push_back(weights[k]);
                }
            }

            int totalInstability = 0;

            for (int k = 0; k < n - 2; k += 2) {
                totalInstability += newWeights[k + 1] - newWeights[k];
            }

            minInstability = min(minInstability, totalInstability);
        }
    }

    cout << minInstability << "\n";
    
    return 0;
}