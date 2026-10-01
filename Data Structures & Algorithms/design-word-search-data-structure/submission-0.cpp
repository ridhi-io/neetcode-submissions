class WordDictionary {
public:

    class TrieNode {
    public:
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;

            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {

        TrieNode* node = root;

        for(char c : word) {

            int index = c - 'a';

            if(node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->isEnd = true;
    }

    bool searchWord(string& word, int index, TrieNode* node) {

        if(index == word.size()) {
            return node->isEnd;
        }

        char c = word[index];

        // Normal character
        if(c != '.') {

            int letter = c - 'a';

            if(node->children[letter] == nullptr) {
                return false;
            }

            return searchWord(
                word,
                index + 1,
                node->children[letter]
            );
        }

        // '.' means any character
        for(int i = 0; i < 26; i++) {

            if(node->children[i] != nullptr) {

                if(searchWord(
                    word,
                    index + 1,
                    node->children[i]
                )) {
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) {

        return searchWord(word, 0, root);
    }
};