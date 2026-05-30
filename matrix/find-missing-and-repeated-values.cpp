class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;

        int xr = 0;
        for (auto &row : grid) {
            for (int i : row) {
                xr ^= i;
            }
        }
        for (int i = 1; i <= N; i++) {
            xr ^= i;
        }

        int bit = xr & -xr;
        int x = 0, y = 0;

        for (auto& row : grid) {
            for (int i : row) {
                if (i & bit)
                    x ^= i;
                else
                    y ^= i;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (i & bit)
                x ^= i;
            else
                y ^= i;
        }

        int cnt = 0;
        for (auto& row : grid) {
            for (int i : row) {
                if (i == x)
                    cnt++;
            }
        }

        if (cnt == 2)
            return {x, y};
        else
            return {y, x};
    }
};