class Solution {
public:
vector<int>par;
vector<int>rnk;
void make_set(int n)
{
    for(int i=1;i<=n;i++)
    {
        rnk[i]=1;
        par[i]=i;
    }

}

int find_set(int node)
{
    if(par[node]==node)return node;
    return par[node]=find_set(par[node]);
}

void union_set(int a ,int b)
{
    int p1=find_set(a);
    int p2=find_set(b);
    if(p1!=p2)
    {
        if(rnk[p1]>=rnk[p2])
        {
            par[p2]=p1;
            rnk[p1]+=rnk[p2];
        }
        else
        {
            par[p1]=p2;
            rnk[p2]+=rnk[p1];
        }
    }
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        int n=edges.size();
        par.resize(n+1);
        rnk.resize(n+1);
        make_set(n);
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            if(find_set(u)==find_set(v))
            {
                ans.push_back(u);
                ans.push_back(v);
            }
            else union_set(u,v);
        }
        return ans;
    }
};
