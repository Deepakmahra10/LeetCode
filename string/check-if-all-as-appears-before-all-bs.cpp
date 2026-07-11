class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        bool seenB = false;

        for (int ch : s) {
            if (ch == 'b') 
                seenB = true;
                
            if(ch == 'a' && seenB)
                return false;
            
        }
        return true;
    }
};