class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0)
            return 0;

        int count = 0;
        int l = 0;
        int distinct = 0;
        unordered_map<int, int> freq;
        for (int r = 0; r < n; r++) {
            if (freq[nums[r]] == 0)
                distinct++;
            freq[nums[r]]++;

            while(distinct > k) {
                freq[nums[l]]--;

                if(freq[nums[l]] == 0){
                    freq.erase(nums[l]);
                    distinct--;
                }

                l++;
            }
            count += r-l+1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};