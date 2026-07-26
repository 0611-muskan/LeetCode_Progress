class Solution {
public:
    vector<int> parent;
    int find(int node){
        if(parent[node]==node)
            return node;
        return parent[node]=find(parent[node]);
    }
    void Union(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu!=pv)
            parent[pu]=pv;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>>edges;
        int n=points.size();
        for(int i=0;i<n;i++){
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];
            int dist=abs(x1-x2)+abs(y1-y2);
            edges.push_back({dist,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
            int cost=0;
        for(auto edge:edges){
            int wt=edge[0];
            int u=edge[1];
            int v=edge[2];
            if(find(u)!=find(v)){
                Union(u,v);
                cost+=wt;
            }
        }
        return cost;
    }
};