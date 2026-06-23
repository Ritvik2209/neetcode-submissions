class Solution {
public:
vector<vector<int>>adj;
vector<bool>vis;
void dfs(int node)
{
    vis[node]=true;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it);
        }
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
 adj.resize(n);
 vis.assign(n,0);
 for(int i=0;i<(int)edges.size();i++)
 {
    int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
 }

 int cnt=0;
 for(int i=0;i<n;i++)
 {
    if(!vis[i])
    {
        dfs(i);
        cnt++;
    }
 }
 return cnt;
    }
};
