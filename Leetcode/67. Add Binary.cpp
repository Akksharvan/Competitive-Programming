class Solution {
public:
    string addBinary(string a, string b) {
        if (size(a) > size(b)) swap(a, b);
        reverse(begin(a), end(a)); reverse(begin(b), end(b));

        char j = '0'; string c;
        for (int i = 0; i < max(size(a), size(b)); i++) {
            if (i >= size(a)) {
                if (b[i] == '1' && j == '1') c += '0';
                else if (b[i] == '1' || j == '1') c += '1', j = '0';
                else c += '0';
            }
            else {
                if (a[i] == '1' && b[i] == '1' && j == '1') c += '1';
                else if (a[i] == '1' && (b[i] == '1' || j == '1')) c += '0', j = '1';
                else if (b[i] == '1' && (a[i] == '1' || j == '1')) c += '0', j = '1';
                else if (j == '1' && (a[i] == '1' || b[i] == '1')) c += '0', j = '1';
                else if (j == '1' || a[i] == '1' || b[i] == '1') c += '1', j = '0';
                else c += '0';
            }
        }

        if (j == '1') c += '1';
        reverse(begin(c), end(c));

        return c;
    }
};