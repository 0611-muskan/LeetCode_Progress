class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int num:nums)
            mp[num]++;
        int mini=INT_MAX, maxi= INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        while(mini<maxi){
            if(mp.find(mini+1)==mp.end())
                ans.push_back(mini+1);
            mini=mini+1;
        }
        return ans;
    }
};