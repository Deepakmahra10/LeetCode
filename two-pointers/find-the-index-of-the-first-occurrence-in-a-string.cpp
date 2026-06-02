class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m > n) return -1;

        for(int i=0; i<=n-m; i++){
            
            string sub = haystack.substr(i, m);
            if(sub == needle){
                return i;
            }
        }
        return -1;
    }
};