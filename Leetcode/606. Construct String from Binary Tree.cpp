static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class Solution {
public:
    string ans = "";
    void pre(TreeNode* root) {
        if (root == nullptr) return; ans += to_string(root->val);

        if (root->left != nullptr || root->right != nullptr) ans += "(", pre(root->left), ans += ")";
        if (root->right != nullptr) ans += "(", pre(root->right), ans += ")";
    }

    string tree2str(TreeNode* root) {
        pre(root);
        return ans;
    }
};