class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> value = {
            {'I',1},{'V',5},{'X',10},
            {'L',50}, {'C',100},
            {'D',500}, {'M',1000}
        };
        int result = 0;
        int preVal = 0;
        for(int i=n-1; i>=0; i--){
            int current = value[s[i]];
            if(current < preVal)
                result -= current;
            else
                result += current;

            preVal = current;
        }
        return result;
    }
};