class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (strs.empty())
            return "";
        sort(strs.begin(), strs.end());
        
        string first = strs[0];
        string last = strs[n-1];

        int i=0;
        while(i < min(first.size(), last.size()) && first[i] == last[i]){
            i++;
        }
        return first.substr(0, i);
    }
};