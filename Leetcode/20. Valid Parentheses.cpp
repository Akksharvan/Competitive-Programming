class Solution {
public:
    bool isValid(string s) {
        stack<char> A;
        for (char &c : s) {
            if (c == '(' || c == '{' || c == '[') A.push(c);
            else if (c == ')' || c == '}' || c == ']') {
                if (A.empty() || (A.top() != char(c - 1)) && (A.top() != char(c - 2))) return 0;
                else A.pop();
            }
        }

        if (!A.empty()) return 0;
        else return 1;
    }
};