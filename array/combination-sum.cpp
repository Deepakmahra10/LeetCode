class Solution {
public:
    void helper(int index, vector<int>& arr, vector<vector<int>>& ans, int k,
                vector<int> &ds) {
        if (index == arr.size()) {
            if (k == 0) {
                ans.push_back(ds);
            }
            return;  
        }

        if (arr[index] <= k) {
            ds.push_back(arr[index]);
            helper(index, arr, ans, k - arr[index], ds);
            ds.pop_back();
        }

        helper(index + 1, arr, ans, k, ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, candidates, ans, target, ds);
        return ans;
    }
};