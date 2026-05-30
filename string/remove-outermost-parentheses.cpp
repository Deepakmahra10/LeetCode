class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        int cnt = 0;

        for (int c : s) {
            if (c == '(') {
                if (cnt > 0)
                    ans += c;
                cnt++;
            }
            if (c == ')') {
                cnt--;
                if (cnt > 0)
                    ans += c;
            }
        }
        return ans;
    }
};