class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& nums, int index) {

        // Every current combination is a valid subset
        result.push_back(current);

        for(int i = index; i < nums.size(); i++) {

            // Skip duplicate choices at the same level
            if(i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            // CHOOSE
            current.push_back(nums[i]);

            // EXPLORE
            backtrack(nums, i + 1);

            // UNDO
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        backtrack(nums, 0);

        return result;
    }
};