class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int maxFreq = 0;
        int start = 0, end = 0;
        unordered_map<char, int> freq;
        while(end < s.size()) {
            freq[s[end]]++;
            maxFreq = max(maxFreq, freq[s[end]]);

            while ((end - start + 1) - maxFreq > k) {
                freq[s[start]]--;
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
            end++;
        }
        return maxLen;
    }
};