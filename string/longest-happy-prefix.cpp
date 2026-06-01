class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();

        for(int i=n-1; i>0; i--){
            if(s.substr(0, i) == s.substr(n-i, i)){
                return s.substr(0, i);
            }
        }
        return "";
    }
};