class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void helperfn(int i, string& s, vector<string>& ds, vector<vector<string>>& ans) {
        int n = s.size();
        if (i == n) {
            ans.push_back(ds);
            return;
        }

        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                ds.push_back(s.substr(i, j-i+1));
                helperfn(j + 1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;

        helperfn(0, s, ds, ans);
        return ans;
    }
};