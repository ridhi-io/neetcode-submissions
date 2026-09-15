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
unordered_map<int,int>inOrderIndex;
int  preIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            inOrderIndex[inorder[i]] = i;
        }
        return build(preorder , 0, inorder.size() - 1);
    }
    private:
    TreeNode*build(vector<int>&preorder , int left , int right){
        if(left > right)
        return nullptr;
        int rootValue = preorder[preIndex ++];
        TreeNode*root = new TreeNode(rootValue);
        int mid = inOrderIndex[rootValue];
        root->left = build(preorder , left , mid - 1);
        root->right = build(preorder, mid + 1, right);
        return root;
    }
};
