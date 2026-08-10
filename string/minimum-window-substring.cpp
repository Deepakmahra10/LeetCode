class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        vector<int> freq(256, 0);
        for (char ch : t) {
            freq[ch]++;
        }

        int l = 0;
        int minLen = INT_MAX;
        int start = -1;
        int cnt = 0;
        for (int r = 0; r < s.size(); r++) {
            if (freq[s[r]] > 0)
                cnt++;
            freq[s[r]]--;

            while(cnt == t.size()) {
                int len = r - l + 1;
                if (len < minLen) {
                    minLen = len;
                    start = l;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0)
                    cnt--;
                l++;
            }
        }
        if (minLen == INT_MAX)
            return "";
        return s.substr(start, minLen);
    }
};