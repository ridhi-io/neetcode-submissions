class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        if (words.find(endWord) == words.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int length = 1;
        words.erase(beginWord);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                if (word == endWord) {
                    return length;
                }

                for (int j = 0; j < word.size(); j++) {
                    char original = word[j];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original) continue;

                        word[j] = ch;

                        if (words.find(word) != words.end()) {
                            q.push(word);
                            words.erase(word);
                        }
                    }

                    word[j] = original;
                }
            }

            length++;
        }

        return 0;
    }
};