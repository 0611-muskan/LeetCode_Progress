class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        vector<bool>present(101,false);
        int mini=INT_MAX, maxi=INT_MIN;
        for(int num:nums){
            present[num]=true;
            mini=min(mini,num);
            maxi=max(maxi,num);
        }
        for(int i=mini+1;i<maxi;i++){
            if(!present[i])
                ans.push_back(i);
        }
        return ans;
    }
};