class Solution {
public:

    vector<vector<int>> dp;

    int solve(int i, int j, string &s, string &t)
    {
        if(j >= t.length())
            return 1;

        if(i >= s.length())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j])
        {
            int pick = solve(i+1, j+1, s, t);

            int notPick = solve(i+1, j, s, t);

            return dp[i][j] = pick + notPick;
        }

        return dp[i][j] = solve(i+1, j, s, t);
    }

    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        dp.assign(n, vector<int>(m, -1));

        return solve(0, 0, s, t);
    }
};