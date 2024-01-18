class Solution {
public:
    vector<int> beautifulIndices (string S, string A, string B, int K) {
        vector<int> C; set<int> D; vector<int> R; int I = 0, J = 0;
        
        while (S.find(A, I) != string::npos) I = S.find(A, I) + 1, C.push_back(I - 1);
        while (S.find(B, J) != string::npos) J = S.find(B, J) + 1, D.insert(J - 1);
        
        for (int &i : C) {
            if (D.lower_bound(i) != end(D) && abs(*D.lower_bound(i) - i) <= K) R.push_back(i);
            else if (D.lower_bound(i) != begin(D) && abs(*prev(D.lower_bound(i)) - i) <= K) R.push_back(i);
        }
        
        return R;
    }
};