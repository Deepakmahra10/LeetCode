class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int, int> mpp;

        for(int i=0; i<n; i++){
            int need = target - numbers[i];

            if(mpp.find(need) != mpp.end()){
                return {mpp[need], i+1};
            }

            //Store current element after checking...
            mpp[numbers[i]] = i+1;
        }
        return {-1, -1};
    }
};