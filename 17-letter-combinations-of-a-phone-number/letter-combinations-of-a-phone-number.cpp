class Solution {
public:
    void helper(int index,vector<string>&res,string &ans,string digits,map<char,string>mpp){
        if(index==digits.length()){
            res.push_back(ans);
            return;
        }
        char x =digits[index];
        for(auto i:mpp[x]){
        ans=ans+i;
        helper(index+1,res,ans,digits,mpp);
        ans.pop_back();    
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,string>mpp;
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";
        string ans="";
        vector<string>res;
        helper(0,res,ans,digits,mpp);
        return res;
    
    }
};