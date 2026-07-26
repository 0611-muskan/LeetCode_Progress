class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       vector<bool>visited(n,false);
       pq.push({0,0});
       int mst=0;
       while(!pq.empty()){
        auto[wt,node]=pq.top();
        pq.pop();
        if(visited[node]) continue;
        visited[node]=true;
        mst+=wt;
        for (int next = 0; next < n; next++) {
            if (!visited[next]){       
                int edgeWt =abs(points[node][0] - points[next][0]) +
            abs(points[node][1] - points[next][1]);
                 pq.push({edgeWt, next});
        }
        }
       }
       return mst;
    }
};