class Solution {
public:
    void solve(int n, int open, int close, string s, vector<string>& res) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }

        if (open < n)
            solve(n, open + 1, close, s + '(', res);
        if (close < open)
            solve(n, open, close + 1, s + ')', res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        solve(n, 0, 0, "", res);
        return res;
    }
};