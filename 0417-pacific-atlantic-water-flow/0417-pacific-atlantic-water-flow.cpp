class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights, int i, int j,
             vector<vector<bool>>& vis) {

        vis[i][j] = true;

        for (auto d : dir) {
            int x = i + d[0];
            int y = j + d[1];

            if (x < 0 || y < 0 || x >= m || y >= n)
                continue;

            if (vis[x][y])
                continue;

            // Reverse flow: move to equal or higher height
            if (heights[x][y] >= heights[i][j])
                dfs(heights, x, y, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific
        for (int i = 0; i < m; i++)
            dfs(heights, i, 0, pacific);

        for (int j = 0; j < n; j++)
            dfs(heights, 0, j, pacific);

        // Atlantic
        for (int i = 0; i < m; i++)
            dfs(heights, i, n - 1, atlantic);

        for (int j = 0; j < n; j++)
            dfs(heights, m - 1, j, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};