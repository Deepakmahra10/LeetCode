class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = n-1;
        int last = n-1;
        vector<int> arr(n);

        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                arr[last] = nums[left] * nums[left];
                left++;
            }else{
                arr[last] = nums[right] * nums[right];
                right--;
            }
            last--;
        }
        return arr;
    }
};