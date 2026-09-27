class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& nums, vector<bool>& used) {

        // We have used all numbers
        if(current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            // Already used
            if(used[i]) {
                continue;
            }

            // CHOOSE
            used[i] = true;
            current.push_back(nums[i]);

            // EXPLORE
            backtrack(nums, used);

            // UNDO
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<bool> used(nums.size(), false);

        backtrack(nums, used);

        return result;
    }
};