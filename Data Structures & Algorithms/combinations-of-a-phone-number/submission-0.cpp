class Solution {
public:

    vector<string> result;
    string current;

    vector<string> phone = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int index) {

        // All digits processed
        if(index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get letters for current digit
        string letters = phone[digits[index] - '0'];

        // Try every letter
        for(char letter : letters) {

            // CHOOSE
            current.push_back(letter);

            // EXPLORE
            backtrack(digits, index + 1);

            // UNDO
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty()) {
            return {};
        }

        backtrack(digits, 0);

        return result;
    }
};