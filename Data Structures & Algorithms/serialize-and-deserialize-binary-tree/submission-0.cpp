class Codec {
public:
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "N,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return buildTree(ss);
    }

private:
    TreeNode* buildTree(stringstream& ss) {
        string value;
        getline(ss, value, ',');

        if(value == "N")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(value));

        node->left = buildTree(ss);
        node->right = buildTree(ss);

        return node;
    }
};