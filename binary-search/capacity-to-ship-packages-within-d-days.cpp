class Solution {
public:
    int dayNeeded(vector<int>& weights, int capacity){
        int sum = 0;
        int days = 1;
        for (int weight : weights) {
            if (sum + weight > capacity) {
                days++;
                sum = weight;
            }else{
                sum += weight;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
       int left = *max_element(weights.begin(), weights.end());
       int right = accumulate(weights.begin(), weights.end(), 0);

        while(left <= right){
            int mid = (left + right)/2;

            int needed = dayNeeded(weights, mid);
            if(needed <= days){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }  
        return left;
    }
};