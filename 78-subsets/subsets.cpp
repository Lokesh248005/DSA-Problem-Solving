class Solution {
public:
    void helper(int index,vector<int>&ds,vector<vector<int>>&res,vector<int>&nums){
        if(index==nums.size()){
            res.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        helper(index+1,ds,res,nums);
        ds.pop_back();
        helper(index+1,ds,res,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>res;
        helper(0,ds,res,nums);
    return res; 
    }
};