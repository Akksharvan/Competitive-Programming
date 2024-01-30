static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    bool F (string &S) {
        for (auto &c : S) if (!isdigit(c) && (c != '-' || size(S) == 1)) return 0;
        return 1;
    }

    int evalRPN (vector<string> &A) {
        stack<int> B; for (auto &i : A) {
            if (F(i)) B.push(stoi(i));
            else {
                int X = B.top(); B.pop();
                int Y = B.top(); B.pop();

                if (i == "+") B.push(X + Y);
                else if (i == "-") B.push(Y - X);
                else if (i == "*") B.push(X * Y);
                else if (i == "/") B.push(Y / X);
            }
        }

        return B.top();
    }
};