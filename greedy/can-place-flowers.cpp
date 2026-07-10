class Solution {
public:
    bool isCorrect(vector<int>& plot) {
        int n = plot.size();
        for (int i = 0; i < n; i++) {
            if (plot[i] == plot[i + 1])
                return false;
        }
        return true;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int timePlanted = 0;
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 0) {
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    timePlanted++;
                }
            }
        }
        if (timePlanted == n) {
            return true;
        }
        return false;
    }
};