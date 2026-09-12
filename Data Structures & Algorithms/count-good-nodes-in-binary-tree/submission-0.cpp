/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return countGood(root, root->val);
    }

private:
    int countGood(TreeNode* node, int maxSoFar) {
        if(node == nullptr)
            return 0;

        int count = 0;

        if(node->val >= maxSoFar) {
            count = 1;
        }

        maxSoFar = max(maxSoFar, node->val);

        count += countGood(node->left, maxSoFar);
        count += countGood(node->right, maxSoFar);

        return count;
    }
};
