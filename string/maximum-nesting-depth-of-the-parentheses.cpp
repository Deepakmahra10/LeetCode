class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int depth = 0;
        int maxDepth = 0;

        for (char c : s) {
            if (c == '(')
                depth++;
            else if (c == ')')
                depth--;

            maxDepth = max(maxDepth, depth);
        }
        return maxDepth;
    }
};
