class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;

    void backtrack(vector<int>& nums, int index) {

        // Current subset is one valid answer
        result.push_back(subset);

        // Try every possible next element
        for(int i = index; i < nums.size(); i++) {

            // Take nums[i]
            subset.push_back(nums[i]);

            // Move forward
            backtrack(nums, i + 1);

            // Undo the choice
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};
