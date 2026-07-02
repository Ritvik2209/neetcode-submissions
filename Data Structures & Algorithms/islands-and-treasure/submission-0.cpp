class Solution {
public:
const int val=(1LL<<31)-1;
vector<vector<bool>>vis;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vis.assign(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    vis[i][j]=true;
                    q.push({{i,j},0});
                }
            }
        }
        vector<int>n_row={0,-1,0,+1};
        vector<int>n_col={-1,0,+1,0};
        while(!(q.empty()))
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int new_row=row+n_row[i];
                int new_col=col+n_col[i];
                if(new_row>=0 && new_row<m && new_col>=0 && new_col<n && vis[new_row][new_col]==0 && grid[new_row][new_col]==val)
                {
                    grid[new_row][new_col]=dis+1;
                    vis[new_row][new_col]=true;
                    q.push({{new_row,new_col},dis+1});
                }
            }
        }
    }
};
