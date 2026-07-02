class Solution {
public:

    void bfs(queue<pair<int,int>> &q,
             vector<vector<bool>> &vis,
             vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};

        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m &&
                   !vis[nr][nc] &&
                   heights[nr][nc] >= heights[r][c])
                {
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m,false));
        vector<vector<bool>> atlantic(n, vector<bool>(m,false));

        queue<pair<int,int>> pq;
        queue<pair<int,int>> aq;

        // Pacific boundary
        for(int i=0;i<n;i++)
        {
            pq.push({i,0});
            pacific[i][0] = true;
        }

        for(int j=1;j<m;j++)
        {
            pq.push({0,j});
            pacific[0][j] = true;
        }

        // Atlantic boundary
        for(int i=0;i<n;i++)
        {
            aq.push({i,m-1});
            atlantic[i][m-1] = true;
        }

        for(int j=0;j<m-1;j++)
        {
            aq.push({n-1,j});
            atlantic[n-1][j] = true;
        }

        bfs(pq,pacific,heights);
        bfs(aq,atlantic,heights);

        vector<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};