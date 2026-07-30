class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i = 0;
        int write = 0;

        while (i < n) {
            char curr = chars[i];
            int cnt = 0;
            while (i < n && (chars[i] == curr)) {
                cnt++;
                i++;
            }

            chars[write++] = curr;

            if (cnt > 1) {
                string s = to_string(cnt);
                for (char c : s)
                    chars[write++] = c;
            }
        }
        return write;
    }
};