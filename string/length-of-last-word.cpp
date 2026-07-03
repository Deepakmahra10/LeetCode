class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss >> word){
           words.push_back(word);
        }
        return words.back().size();
    }
};