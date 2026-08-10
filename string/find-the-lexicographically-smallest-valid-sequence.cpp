class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (m > n)
            return {};

        vector<int> suf(m, n);
        int j = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            while (j >= 0 && word1[j] != word2[i])
                j--;

            if (j >= 0) {
                suf[i] = j;
                j--;
            }
        }

        vector<int> ans;
        int i = 0;
        bool mismatchUsed = false;
        for (int j = 0; j < m; j++) {
            while (i < n) {
                if (word1[i] == word2[j]) {
                    ans.push_back(i);
                    i++;
                    break;
                }
                if (!mismatchUsed) {
                    if (j == m-1) {
                        ans.push_back(i);
                        mismatchUsed = true;
                        i++;
                        break;
                    }
                    if (suf[j + 1] != n && suf[j + 1] > i) {
                        ans.push_back(i);
                        mismatchUsed = true;
                        i++;
                        break;
                    }
                }
                i++;
            }
            if (ans.size() != j + 1)
                return {};
        }
        return ans;
    }
};