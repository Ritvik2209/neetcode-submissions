class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    vector<int> dRow = {-1, 0, 1, 0};
    vector<int> dCol = {0, 1, 0, -1};

    int solve(int row, int col, vector<vector<int>>& matrix)
    {
        if(dp[row][col] != -1)
            return dp[row][col];

        //int maxLength = 1;
        dp[row][col]=1;

        for(int i = 0; i < 4; i++)
        {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            if(newRow >= 0 && newRow < n &&
               newCol >= 0 && newCol < m &&
               matrix[newRow][newCol] > matrix[row][col])
            {
                dp[row][col] = max(
                    dp[row][col],
                    1 + solve(newRow, newCol, matrix)
                );
            }
        }

        return dp[row][col];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        n = matrix.size();
          m = matrix[0].size();

        dp.assign(n, vector<int>(m, -1));

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
    
            for(int j = 0; j < m; j++)
            {
                ans = max(ans, solve(i, j, matrix));
            }
        }

        return ans;
    }
};