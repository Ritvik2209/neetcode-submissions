class Solution {
public:
vector<int>row={0,-1,0,+1};
vector<int>col={-1,0,1,0};
vector<vector<int>>vis;
void dfs(int i,int j,int n,int m,vector<vector<char>>&grid)
{
    vis[i][j]=true;
    for(int k=0;k<4;k++)
    {
        int r=i+row[k];
        int c=j+col[k];
        if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && grid[r][c]=='1')
        {
            dfs(r,c,n,m,grid);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vis.resize(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    dfs(i,j,n,m,grid);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};