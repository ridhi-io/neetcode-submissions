class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& candidates, int target, int index) {

        // We found a valid combination
        if(target == 0) {
            result.push_back(current);
            return;
        }

        // Target became negative
        if(target < 0) {
            return;
        }

        for(int i = index; i < candidates.size(); i++) {

            // CHOOSE
            current.push_back(candidates[i]);

            // EXPLORE
            backtrack(candidates, target - candidates[i], i);

            // UNDO
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return result;
    }
};