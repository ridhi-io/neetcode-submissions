class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open, int close, int n) {

        // We used all parentheses
        if(current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        // We can add '('
        if(open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        // We can add ')'
        if(close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {

        backtrack("", 0, 0, n);

        return result;
    }
};