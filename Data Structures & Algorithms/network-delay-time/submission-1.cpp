class Solution {
public:
const int MAX=1e9;
vector<vector<pair<int,int>>>adj;
vector<int>dist;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        adj.resize(n+1);
        dist.assign(n+1,MAX);
        dist[k]=0;
        for(int i=0;i<(int)times.size();i++)
        {
            int u=times[i][0];
            int v=times[i][1];
            int t=times[i][2];
            adj[u].push_back({v,t});
        }
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq    ;
       // priority_queue<pair<int,int>>pq;
        pq.push({0,k});
        while(!(pq.empty()))
        {
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int v=it.first;
                int distance=it.second;
                if(time+distance<dist[v])
                {
                    dist[v]=time+distance;
                    pq.push({dist[v],v});
                }
            }
        }
        int mx=-1;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)return -1;
            else mx=max(mx,dist[i]);
        }
        return mx;
    }
};
