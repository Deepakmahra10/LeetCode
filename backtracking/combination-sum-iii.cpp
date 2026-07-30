class Solution {
public:
    void helper(int ind, int k, int target, vector<vector<int>>& ans,
                vector<int>& ds) {
        if (k == 0) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        for (int i = ind; i <= 9; i++) {
            if (i > target)
                break;

            if(i <= target){
                ds.push_back(i);
                helper(i + 1, k - 1, target - i, ans, ds);
                ds.pop_back();
            }
            
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        helper(1, k, n, ans, ds);
        return ans;
    }
};