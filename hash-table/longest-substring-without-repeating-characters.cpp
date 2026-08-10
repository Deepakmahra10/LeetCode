class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int l = 0, r = 0;
        vector<int> mp(256, -1);
        while(r < s.size()) {
            if (mp[s[r]] != -1)
                l = max(mp[s[r]] + 1, l);
            mp[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};