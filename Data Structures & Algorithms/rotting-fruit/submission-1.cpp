class Solution {
public:
vector<vector<int>>adj;
       vector<vector<bool>>vis;
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
      vis.assign(n, vector<bool>(m, 0));

queue<pair<pair<int,int>,int>>q;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]==2)
        {
            q.push({{i,j},0});
        }
    }
}
vector<int>n_row={0,-1,0,1};
vector<int>n_col={-1,0,+1,0};
int t=0;
while(!(q.empty()))
{
    int row=q.front().first.first;
    int col=q.front().first.second;
    int time=q.front().second;
    t=max(t,time);
    q.pop();
    for(int i=0;i<4;i++)
    {
    int new_row=row+n_row[i];
    int new_col=col+n_col[i];
    if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && vis[new_row][new_col]==0 && grid[new_row][new_col]==1)
    {
        vis[new_row][new_col]=1;
        q.push({{new_row,new_col},t+1});
    }
    }
    

}

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]==1 && vis[i][j]==0)return -1;
    }
}
return t;


    }
};
