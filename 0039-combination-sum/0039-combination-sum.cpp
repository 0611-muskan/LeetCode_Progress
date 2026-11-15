class Solution {
public:
    void solve(int i,vector<int>&candidates,int target, vector<vector<int>>&ans,vector<int>&res){
        if(i==candidates.size()){
            if(target==0){
                ans.push_back(res);
            }
            return;
        }
        if(candidates[i]<=target){
            res.push_back(candidates[i]);
            solve(i,candidates,target-candidates[i],ans,res);
            res.pop_back();
        }
        solve(i+1,candidates,target,ans,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>res;
        vector<vector<int>>ans;
        solve(0,candidates,target,ans,res);
        return ans;
    }
};