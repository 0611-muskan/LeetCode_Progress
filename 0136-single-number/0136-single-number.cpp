class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num:nums)
         mp[num]++;
        for (int num : nums) {
            if (mp[num] == 1)
                return num;
        }
        return -1;
    }
};