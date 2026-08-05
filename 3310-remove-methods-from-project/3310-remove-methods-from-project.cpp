class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        // Find all suspicious methods using BFS
        vector<bool> suspicious(n, false);
        queue<int> q;

        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nei : adj[node]) {
                if (!suspicious[nei]) {
                    suspicious[nei] = true;
                    q.push(nei);
                }
            }
        }

        // Check if any safe method calls a suspicious method
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return all non-suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};