class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        vector<vector<char>> bucket(n + 1);

        for (auto& p : mp) {
            bucket[p.second].push_back(p.first);
        }

        string result = "";
        for (int i = n; i >= 1; i--) {
            for (char c : bucket[i]) {
                result.append(i, c);
            }
        }

        return result;
    }
};