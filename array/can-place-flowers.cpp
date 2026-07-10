class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int timePlanted = 0;
        vector<int> temp = flowerbed;

        for (int i = 0; i < m; i++) {
            if (temp[i] == 0) {

                bool left = (i == 0 || temp[i - 1] == 0);
                bool right = (i == m - 1 || temp[i + 1] == 0);

                if (left && right) {
                    temp[i] = 1;
                    timePlanted++;
                }
            }
        }
        return timePlanted >= n;
    }
};