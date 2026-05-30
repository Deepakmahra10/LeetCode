class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        // 1. Remove extra spaces
        int i = 0, j = 0;

        while (j < n) {
            while (j < n && s[j] == ' ') j++;

            while (j < n && s[j] != ' ') {
                s[i++] = s[j++];
            }

            while (j < n && s[j] == ' ') j++;

            if (j < n) s[i++] = ' ';
        }

        s.resize(i);

        // 2. Reverse whole string
        reverse(s.begin(), s.end());

        // 3. Reverse each word
        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};