class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        vector<int>vis(n,0);
        q.push(source);
        vis[source] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u==destination){
                return true;
            }
            for(auto v : adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        return false;
    }
};