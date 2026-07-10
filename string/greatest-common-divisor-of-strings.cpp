class Solution {
public:
    bool isDivisor(string s, string p) {
        int n = s.size();
        int m = p.size();
        if (n % m != 0) {
            return false;
        }
        string temp = "";
        while (temp.size() < n) {
            temp += p;
        }
        return temp == s;
    }

    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        for (int len = min(n, m); len >= 1; len--) {
            if (n % len != 0 || m % len != 0) {
                continue;
            }
            string candidate = str1.substr(0, len);
            if (isDivisor(str1, candidate) && isDivisor(str2, candidate)) {
                return candidate;
            }
        }
        return "";
    }
};