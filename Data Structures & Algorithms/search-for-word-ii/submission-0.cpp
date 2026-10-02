class Solution {
public:

    class TrieNode {
    public:
        TrieNode* children[26];
        string word;

        TrieNode() {
            word = "";

            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> result;

    void insert(string word) {

        TrieNode* node = root;

        for(char c : word) {

            int index = c - 'a';

            if(node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int row,
             int col,
             TrieNode* node) {

        // Boundary check
        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size()) {
            return;
        }

        // Already visited
        if(board[row][col] == '#') {
            return;
        }

        char c = board[row][col];

        int index = c - 'a';

        // Character Trie mein nahi hai
        if(node->children[index] == nullptr) {
            return;
        }

        node = node->children[index];

        // Word mil gaya
        if(node->word != "") {
            result.push_back(node->word);

            // Duplicate avoid karne ke liye
            node->word = "";
        }

        // Mark visited
        board[row][col] = '#';

        // Down
        dfs(board, row + 1, col, node);

        // Up
        dfs(board, row - 1, col, node);

        // Right
        dfs(board, row, col + 1, node);

        // Left
        dfs(board, row, col - 1, node);

        // Undo / Backtrack
        board[row][col] = c;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        // Build Trie
        for(string word : words) {
            insert(word);
        }

        // Start DFS from every cell
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {

                dfs(board, row, col, root);
            }
        }

        return result;
    }
};