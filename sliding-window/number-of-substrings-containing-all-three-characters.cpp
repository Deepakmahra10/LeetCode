class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int ans = 0;
        vector<int> freq(3, 0);

        for(int j=0; j<s.size(); j++){
            freq[s[j] - 'a']++;

            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                ans += s.size() - j;

                freq[s[i]-'a']--;
                i++;
            }
        }
        return ans;
    }
};