class PrefixTree {
public:

    PrefixTree* children[26];
    bool isEnd;

    PrefixTree() {
        isEnd = false;

        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    void insert(string word) {

        PrefixTree* node = this;

        for(char c : word) {

            int index = c - 'a';

            if(node->children[index] == nullptr) {
                node->children[index] = new PrefixTree();
            }

            node = node->children[index];
        }

        node->isEnd = true;
    }

    bool search(string word) {

        PrefixTree* node = this;

        for(char c : word) {

            int index = c - 'a';

            if(node->children[index] == nullptr) {
                return false;
            }

            node = node->children[index];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {

        PrefixTree* node = this;

        for(char c : prefix) {

            int index = c - 'a';

            if(node->children[index] == nullptr) {
                return false;
            }

            node = node->children[index];
        }

        return true;
    }
};