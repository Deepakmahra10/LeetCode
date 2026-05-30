class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;

        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                if (!st.empty() && st.top() ==  '(') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
            i++;
        }
        return st.size();
    }
};