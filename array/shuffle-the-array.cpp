class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> first(nums.begin(), nums.begin()+n);
        vector<int> second(nums.begin()+n, nums.end());
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            ans.push_back(first[i]);
            ans.push_back(second[i]);
        }
        return ans;
    }
};