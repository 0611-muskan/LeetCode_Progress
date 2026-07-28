class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                max_product=max(max_product,(nums[i]-1)*(nums[j]-1));
            }
        }
        return max_product;
    }
};