static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using OST =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> resultArray (vector<int> &A) {
        int N = size(A); vector<int> B, C; OST<pair<int, int>> D, E;
        B.push_back(A[0]); D.insert({A[0], 0}); C.push_back(A[1]); E.insert({A[1], 1});
        
        for (int i = 2; i < N; i++) {
            int X = size(B) - D.order_of_key({A[i], N});
            int Y = size(C) - E.order_of_key({A[i], N});
            
            if (Y > X || (X == Y && size(C) < size(B))) C.push_back(A[i]), E.insert({A[i], i});
            else B.push_back(A[i]), D.insert({A[i], i});
        }
        
        for (auto &i : C) B.push_back(i);
        return B;
    }
};