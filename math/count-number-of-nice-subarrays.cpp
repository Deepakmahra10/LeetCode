class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if(k<0) return 0;
        int i = 0;
        int oddSum = 0;
        int ans = 0;
        for (int j = i; j < nums.size(); j++) {
            oddSum += nums[j]%2;
            while (oddSum > k) {
                oddSum -= nums[i]%2;
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};