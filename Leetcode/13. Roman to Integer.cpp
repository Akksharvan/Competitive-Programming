class Solution {
public:
    int romanToInt(string s) {
        int R = 0;
        int N = size(s);

        for (int i = 0; i < N; i++) {
            if (i == N - 1) {
                if (s[i] == 'I') R += 1;
                if (s[i] == 'V') R += 5;

                if (s[i] == 'X') R += 10;
                if (s[i] == 'L') R += 50;

                if (s[i] == 'C') R += 100;
                if (s[i] == 'D') R += 500;

                if (s[i] == 'M') R += 1000;
                continue;
            }

            if (s[i] == 'I') {
                if (s[i + 1] == 'V') { R += 4; i++; }
                else if (s[i + 1] == 'X') { R += 9; i++; }
                else R += 1;
            }
            else if (s[i] == 'X') {
                if (s[i + 1] == 'L') { R += 40; i++; }
                else if (s[i + 1] == 'C') { R += 90; i++; }
                else R += 10;
            }
            else if (s[i] == 'C') {
                if (s[i + 1] == 'D') { R += 400; i++; }
                else if (s[i + 1] == 'M') { R += 900; i++; }
                else R += 100;
            }
            else if (s[i] == 'V') R += 5;
            else if (s[i] == 'L') R += 50;
            else if (s[i] == 'D') R += 500;
            else R += 1000;
        }

        return R;
    }
};