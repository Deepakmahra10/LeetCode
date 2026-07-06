class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n = word1.size();
        int m = word2.size();

        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            ans = ans + word1[i];
            ans = ans + word2[j];
            i++;
            j++;
        }
        if (n > m) {
            ans += word1.substr(i, n);
        } else {
            ans += word2.substr(j, m);
        }

        return ans;
    }
};