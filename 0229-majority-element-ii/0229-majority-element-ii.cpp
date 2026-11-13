class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0;
        int c2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        int n=nums.size();
        for(auto i:nums){
            if(ele1==i)
                c1++;
            else if(ele2==i)
                c2++;
            else if(c1==0){
                c1=1;
                ele1=i;
            }
            else if(c2==0){
                c2=1;
                ele2=i;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(auto i:nums){
            if(i==ele1)
                c1++;
            if(i==ele2)
                c2++;
        }
        vector<int> ans;
        if(c1>n/3)
            ans.push_back(ele1);
        if(c2>n/3)
            ans.push_back(ele2);
        return ans;
    }
};