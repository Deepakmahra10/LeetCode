class Solution {
public:
    bool isSorted(vector<int>& rotated){
        int n = rotated.size();
        for(int i=0; i<n; i++){
            if(rotated[i] < rotated[i-1]){
                return false;
            }
        }
        return true;
    }

    bool check(vector<int>& nums) {
        int n = nums.size();
        fora(int i=0; i<n; i++){
            vector<int> rotated;
            for(int j=0; j<n; j++){
                rotated.push_back(nums[(i+j)%n]);
            }
            if(isSorted(rotated)){
                return true;
            }
        }
        return false;
    }
};