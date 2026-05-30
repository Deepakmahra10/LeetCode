class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // Store known languages for each user
        vector<unordered_set<int>> knows(m+1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                knows[i+1].insert(lang);
            }
        }

        // Find problematic users (friendships where they can't talk)
        unordered_set<int> problematic;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool canTalk = false;
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk) {
                problematic.insert(u);
                problematic.insert(v);
            }
        }

        // If no problematic users, no need to teach
        if (problematic.empty()) return 0;

        int ans = INT_MAX;
        // Try teaching each language
        for (int lang = 1; lang <= n; lang++) {
            int cnt = 0;
            for (int user : problematic) {
                if (!knows[user].count(lang)) {
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};
