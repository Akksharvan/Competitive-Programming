#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	
	int cow_num;
	int max_pos;
	cin >> cow_num >> max_pos;

	vector<int> x_vals(cow_num);
	vector<int> y_vals(cow_num);
	set<int> vfence;
	set<int> hfence;
	for (int c = 0; c < cow_num; c++) {
		cin >> x_vals[c] >> y_vals[c];
		vfence.insert(x_vals[c] + 1);
		hfence.insert(y_vals[c] + 1);
	}
	
	int min_imbalance = cow_num;
	for (int v : vfence) {
		for (int h : hfence) {
			int top_left = 0;
			int top_right = 0;
			int bottom_left = 0;
			int bottom_right = 0;
			
			for (int c = 0; c < cow_num; c++) {
				if (x_vals[c] < v && y_vals[c] > h) {
					top_left++;
				} else if (x_vals[c] > v && y_vals[c] > h) {
					top_right++;
				} else if (x_vals[c] < v && y_vals[c] < h) {
					bottom_left++;
				} else if (x_vals[c] > v && y_vals[c] < h){
					bottom_right++;
				}
			}
			
			min_imbalance = min(
				min_imbalance,
				max({top_left, top_right, bottom_left, bottom_right})
			);
		}
	}

	cout << min_imbalance << endl;
}