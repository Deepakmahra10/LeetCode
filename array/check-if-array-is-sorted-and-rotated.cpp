class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            bool sorted = true;
            for (int i = 1; i < n; i++) {
                if (nums[i - 1] > nums[i]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted)
                return true;

            int last = nums[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                nums[j + 1] = nums[j];
            }
            nums[0] = last;
        }

        return false;
    }
};