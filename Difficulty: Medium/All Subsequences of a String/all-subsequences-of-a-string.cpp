class Solution {
  public:
    void helper(int index,string &s,vector<string>&ans, string at){
        if(index>=s.length()){
            ans.push_back(at);
            return;
        }
        char temp =s[index];
        at+=temp;
        helper(index+1,s,ans,at);
        at.pop_back();
        helper(index+1,s,ans,at);
        
    }
    vector<string> powerSet(string &s) {
        vector<string>ans;
        string ds ="";
        helper(0,s,ans,ds);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};