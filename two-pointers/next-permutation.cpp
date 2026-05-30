class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // find break point :
        int ind = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // if break point doesn't exist:
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find next greater  element & swap it with nums[index] :
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // reverse the right half:
        reverse(nums.begin() + ind + 1, nums.end());
    }
};