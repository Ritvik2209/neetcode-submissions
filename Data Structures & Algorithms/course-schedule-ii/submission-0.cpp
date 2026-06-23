class Solution {
public:
vector<vector<int>>adj;
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
    vector<int>in_degree(n,0);
    adj.resize(n);
    for(int i=0;i<(int)pre.size();i++)
    {
        int u=pre[i][0];
        int v=pre[i][1];
        adj[v].push_back(u);
        in_degree[u]++;
    }
    queue<int>q;
    vector<int>topo_sort;
for(int i=0;i<n;i++)if(in_degree[i]==0)q.push(i);
while(!(q.empty()))
{
    int node=q.front();
    topo_sort.push_back(node);
    q.pop();
    for(auto it:adj[node])
{
    in_degree[it]--;
    if(in_degree[it]==0)q.push(it);
}
    
}

if(topo_sort.size()==n)return topo_sort;
else 
{
    topo_sort.clear();
    return topo_sort;
}

        
    }
};
