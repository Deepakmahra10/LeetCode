class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n != m)
            return false;

        int lastS[256] = {0};
        int lastT[256] = {0};

        for (int i = 0; i < n; i++) {
            if(lastS[s[i]] != lastT[t[i]])
                return false;
            
            lastS[s[i]] = i+1;
            lastT[t[i]] = i+1;
        }
        return true;
    }
};