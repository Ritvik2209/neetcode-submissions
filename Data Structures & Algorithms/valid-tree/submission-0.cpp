class Solution {
public:
vector<int>par;
vector<int>rnk;
void make_set(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        rnk[i]=1;
    }
}
int find_set(int n)
{
    if(par[n]==n)return n;
    return par[n]=find_set(par[n]);
}
void union_set(int a, int b)

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
    bool validTree(int n, vector<vector<int>>& edges) {

            int e_size=edges.size();
            par.resize(n);
            rnk.resize(n);
            make_set(n);
            int com=n;
            for(int i=0;i<e_size;i++)
            {
                int u=edges[i][0];
                int v=edges[i][1];
               if(find_set(u)==find_set(v))return false;
               else
               {
                union_set(u,v);
                com--;
               }
            }
            if(e_size==n-1 && com==1)return true;
            return false;

    }
};
