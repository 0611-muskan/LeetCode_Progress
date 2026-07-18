class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int max_volume=0;
        while(left<right){
        int h=min(height[left],height[right]);
        int w=right-left;
        max_volume=max(max_volume,h*w);
        if(height[left]<height[right])
        left++;
        else
        right--;
        }
        return max_volume;
    }
};