class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> result;

        int maxVal = *max_element(candies.begin(), candies.end());
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxVal);
        }

        return result;
    }
};