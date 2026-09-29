class Solution {
public:

    vector<vector<string>> result;
    vector<string> current;

    bool isPalindrome(string& s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s, int index) {

        // Entire string has been used
        if(index == s.size()) {
            result.push_back(current);
            return;
        }

        // Try every possible substring
        for(int i = index; i < s.size(); i++) {

            // Only choose palindrome substring
            if(isPalindrome(s, index, i)) {

                // CHOOSE
                current.push_back(s.substr(index, i - index + 1));

                // EXPLORE
                backtrack(s, i + 1);

                // UNDO
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        backtrack(s, 0);

        return result;
    }
};