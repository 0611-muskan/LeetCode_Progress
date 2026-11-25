
class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ds,
               vector<vector<int>>& ans, vector<int>& vis) {

        // Base case
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (!vis[i]) {

                // Pick
                vis[i] = 1;
                ds.push_back(nums[i]);

                // Recursive call
                solve(nums, ds, ans, vis);

                // Backtrack
                ds.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> vis(nums.size(), 0);

        solve(nums, ds, ans, vis);

        return ans;
    }
};
