class Solution {
public:
    vector<vector<bool>> vis;
    vector<int> row = {-1,0,1,0};
    vector<int> col = {0,1,0,-1};

    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        vis[i][j] = true;

        int area = 1;

        for(int k=0;k<4;k++)
        {
            int nr = i + row[k];
            int nc = j + col[k];

            if(nr>=0 && nr<grid.size() &&
               nc>=0 && nc<grid[0].size() &&
               !vis[nr][nc] &&
               grid[nr][nc]==1)
            {
                area += dfs(nr,nc,grid);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vis.assign(n, vector<bool>(m,false));

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] && !vis[i][j])
                {
                    ans = max(ans, dfs(i,j,grid));
                }
            }
        }

        return ans;
    }
};