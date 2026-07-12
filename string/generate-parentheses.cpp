class Solution {
public:
    bool isValid(string curr){
        int balance = 0;

        for(char ch : curr){
            if(ch == '(')
                balance++;
            else if(ch == ')')
                balance--;
            
            if(balance<0)
            return false;
        }
        return balance == 0;
    }
    void generate(int n, string curr, vector<string>& ans){
        if(curr.size() == 2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }
            return;
        }

        generate(n, curr + ')', ans);
        generate(n, curr + '(', ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, "", ans);
        return ans;
    }
};