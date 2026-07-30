class Solution {
public:
    void helperfn(int ind, int k, vector<vector<int>>& ans, vector<int>& arr,
                  vector<int> ds) {
        if (k == 0) {
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<arr.size(); i++){
            if(i>ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > k) break;

            ds.push_back(arr[i]);
            helperfn(i + 1, k - arr[i], ans, arr, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;

        helperfn(0, target, ans, candidates, ds);
        return ans;
    }
};