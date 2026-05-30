class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + nums[i - 1];
        }
        long long mx = 1;
        long long low = 0, high = 1;
        while (high < n) {
            if ((long long)nums[high]*(high - low) -
                    (pref[high] - pref[low]) <=
                k) {
                high++;
            } else {
                high++;
                low++;
            }
            mx = max(mx, high - low);
        }
        return mx;
    }
};