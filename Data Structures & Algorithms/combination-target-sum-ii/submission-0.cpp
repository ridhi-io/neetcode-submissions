class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& candidates, int target, int index) {

        if(target == 0) {
            result.push_back(current);
            return;
        }

        for(int i = index; i < candidates.size(); i++) {

            // Skip duplicate values at the same level
            if(i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // If number is bigger than target,
            // no later number will work either
            if(candidates[i] > target) {
                break;
            }

            // CHOOSE
            current.push_back(candidates[i]);

            // EXPLORE
            // i + 1 because each number can be used only once
            backtrack(candidates, target - candidates[i], i + 1);

            // UNDO
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return result;
    }
};