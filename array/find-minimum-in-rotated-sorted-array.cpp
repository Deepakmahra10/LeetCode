class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int minVal = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[low] <= nums[high]){
                minVal = min(minVal, nums[low]);
                break;
            }
            if(nums[mid] <= nums[high]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return nums[low];
    }
};