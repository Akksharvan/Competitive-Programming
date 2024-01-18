class Solution {
public:
    bool isSameTree (TreeNode* P, TreeNode* Q) {
        queue<TreeNode *> QU;
        QU.push(P); QU.push(Q);

        while (!QU.empty()){
            TreeNode * Q2 = QU.front(); QU.pop();
            TreeNode * Q1 = QU.front(); QU.pop();

            if (Q1 == nullptr && Q2 == nullptr) continue;
            if (Q1 == nullptr || Q2 == nullptr) return 0;
            if (Q1 -> val != Q2 -> val) return 0;
            
            QU.push(Q1 -> left); QU.push(Q2 -> left);
            QU.push(Q1-> right); QU.push(Q2 -> right);
        }

        return 1;
    }
};