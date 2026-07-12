class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;

        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        vector<int> ans;
        for (int x : arr) {
            ans.push_back(lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1);
        }
        return ans;
    }
};