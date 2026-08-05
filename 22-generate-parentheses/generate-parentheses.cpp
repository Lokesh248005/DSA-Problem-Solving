class Solution {
public:
    void helper(vector<string>&res,string&ans,int n,int open,int close){
        if(ans.length()==(2*n)){
            res.push_back(ans);
            return;
        }
        if(open<n){
            ans=ans+'(';
            helper(res,ans,n,open+1,close);
            ans.pop_back();
        }
        if(close<open){
            ans=ans+')';
            helper(res,ans,n,open,close+1);
            ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string ans="";
        helper(res,ans,n,0,0);
        return res;
    }
};