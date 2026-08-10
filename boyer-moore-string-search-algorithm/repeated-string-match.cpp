class Solution {
public:
    bool rabinKarp(string text, string pattern) {
        int n = text.size();
        int m = pattern.size();

        if (m > n) return false;

        const long long mod = 1e9 + 7;
        const long long base = 256;

        long long patternHash = 0;
        long long windowHash = 0;
        long long power = 1;

        for (int i = 0; i < m - 1; i++) {
            power = (power * base) % mod;
        }

        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * base + pattern[i]) % mod;
            windowHash = (windowHash * base + text[i]) % mod;
        }

        for (int i = 0; i <= n - m; i++) {
            if (patternHash == windowHash) {
                if (text.substr(i, m) == pattern) {
                    return true;
                }
            }

            if (i < n - m) {
                windowHash = (windowHash - text[i] * power) % mod;
                if (windowHash < 0) windowHash += mod;

                windowHash = (windowHash * base + text[i + m]) % mod;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string repeated = "";
        int count = 0;

        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        if (rabinKarp(repeated, b)) return count;

        repeated += a;
        if (rabinKarp(repeated, b)) return count + 1;

        return -1;
    }
};