class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n =nums.size();
        int i=0;
        int ans=0;
        while(i<n){
            if(mpp.find(nums[i])!=mpp.end()){
                int a = i-mpp[nums[i]];
                if(a<=k) return true;
            }
            mpp[nums[i]]=i;
            i++;
        }
        return false;
    }
};