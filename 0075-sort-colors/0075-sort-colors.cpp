class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cut0=0,cut1=0,cut2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) cut0++;
            else if(nums[i]==1) cut1++;
            else cut2++;
        }
        for(int i=0;i<cut0;i++) nums[i]=0;
        for(int i=cut0;i<cut0+cut1;i++) nums[i]=1;
        for(int i=cut0+cut1;i<nums.size();i++) nums[i]=2;
    }
};