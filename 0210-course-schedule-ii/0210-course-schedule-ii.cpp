class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>&visited,vector<int>&pathVisited,stack<int>&st){
        visited[node]=1;
        pathVisited[node]=1;
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor,adj,visited,pathVisited,st))
                    return true;
        }
        else if(pathVisited[neighbor])
            return true;
        }
        pathVisited[node]=0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites)
            adj[it[1]].push_back(it[0]);
        stack<int>st;
        vector<int> ans;
        vector<int>visited(numCourses,0);
        vector<int>pathVisited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
                if(dfs(i,adj,visited,pathVisited,st))
                    return {};
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};