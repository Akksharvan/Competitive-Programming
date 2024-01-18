class Solution {
public:
    bool isPalindrome (string S) {
        vector<char> A;
        for (char &c : S) if ((97 <= tolower(c) && tolower(c) <= 122) || (48 <= tolower(c) && tolower(c) <= 57)) A.push_back(tolower(c));

        for (int i = 0; i < size(A) / 2; i++) if (A[i] != A[size(A) - (i + 1)]) return 0;
        return 1;
    }
};