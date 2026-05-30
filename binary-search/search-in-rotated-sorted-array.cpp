class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;

            // Left Half Sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    // Eleminate Right Half
                    high = mid - 1;
                } else {
                    // Eleminate left Half
                    low = mid + 1;
                }

            }
            // Right Half Sorted
            else {
                if (nums[mid] <= target && target <= nums[high]) {
                    // Eleminate left Half
                    low = mid + 1;
                } else {
                    // Eleminate Right Half
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};