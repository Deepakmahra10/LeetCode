class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0;

        for (int i = 0; i < k; i++)
            leftSum += cardPoints[i];

        int ans = leftSum;
        int rightSum= 0;
        for (int i = k-1; i>=0; i--) {
            leftSum -= cardPoints[i];

            rightSum += cardPoints[n - (k-i)];
            ans = max(ans, leftSum+rightSum);
        }
        return ans;
    }
};