class Solution {
public:
    vector<string> ans;
    void dfs(string& num, int target, int ind, string path, long long value,
             long long last) {
        if (ind == num.size()) {
            if (value == target)
                ans.push_back(path);

            return;
        }
        for (int i = ind; i < num.size(); i++) {
            if (i > ind && num[ind] == '0')
                break;
            string currStr = num.substr(ind, i - ind + 1);
            long curr = stol(currStr);
            if (ind == 0)
                dfs(num, target, i + 1, currStr, curr, curr);
            else {
                dfs(num, target, i + 1, path + "+" + currStr, value + curr,
                    +curr);
                dfs(num, target, i + 1, path + "-" + currStr, value - curr,
                    -curr);
                dfs(num, target, i + 1, path + "*" + currStr,
                    value - last + last * curr, last * curr);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        dfs(num, target, 0, "", 0, 0);
        return ans;
    }
};