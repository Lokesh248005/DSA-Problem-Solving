class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =nums.size();
        int i=0;
        int count =0;
        int ele;
        while(i<n){
            if(count==0){
                ele=nums[i];
                count =1;
            }
            else if(nums[i]==ele){
                count++;
            }
            else{
                count--;
            }
        i++;
        }

    
    int count2 = 0;
    for(int j=0;j<n;j++){
        if(nums[j]==ele) count2++;
    }
    if(count2>(n/2)) return ele;
    return 0;
    }
};