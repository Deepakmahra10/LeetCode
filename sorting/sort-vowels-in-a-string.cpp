class Solution {
public:
    string sortVowels(string s) {
        // Function to check vowel
        auto isVowel = [](char c) {
            char lower = tolower(c);
            return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
        };

        // Extract vowels
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) vowels.push_back(c);
        }

        // Sort vowels by ASCII
        sort(vowels.begin(), vowels.end());

        // Fill result string
        string t = s;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                t[i] = vowels[j++];
            }
        }
        return t;
    }
};
