class Solution {
public:
    int countPartition(vector<int>& arr, int maxSum) {
        int n = arr.size();
        int parts = 1;
        long long subArraySum = 0;

        for (int i = 0; i < n; i++) {
            if (subArraySum + arr[i] <= maxSum) {
                subArraySum += arr[i];
            } else {
                parts++;
                subArraySum = arr[i];
            }
        }
        return parts;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low - ((low - high) / 2);

            int partition = countPartition(nums, mid);
            if (partition > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};