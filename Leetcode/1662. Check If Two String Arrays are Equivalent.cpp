class Solution {
public:
    bool arrayStringsAreEqual(vector<string> &A, vector<string> &B) {
        string C, D; for (string &s : A) C += s; for (string &s : B) D += s;
        return (C == D);
    }
};