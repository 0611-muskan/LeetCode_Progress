class Solution {
public:
void solve(int index,vector<int>&candidates,int target,vector<vector<int>>&ans, vector<int>&res){
    if(target==0){
        ans.push_back(res);
        return ;
    }
    for(int i=index;i<candidates.size();i++){
        if(i> index && candidates[i]==candidates[i-1]) continue;
        if(candidates[i]<=target){
        res.push_back(candidates[i]);
        solve(i+1,candidates,target-candidates[i],ans,res);
        res.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>res;
        vector<vector<int>>ans;
        solve(0,candidates,target,ans,res);
        return ans;
    }
};