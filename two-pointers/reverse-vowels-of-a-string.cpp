class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s) {
        int n = s.size();
        string vowels;
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels += ch;
            }
        }
        reverse(vowels.begin(), vowels.end());
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j++];
            }
        }
        return s;
    }
};