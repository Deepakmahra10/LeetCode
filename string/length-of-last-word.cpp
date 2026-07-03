class Solution {
public:
    int lengthOfLastWord(string s) {
       int currlen = 0;
       int lastlen = 0;

       for(char c : s){
        if(c != ' '){
            currlen++;
        }else if(currlen > 0){
            lastlen = currlen;
            currlen = 0;
        }
       }
       if(currlen > 0){
        lastlen = currlen;
       }
       return lastlen;
    }
};