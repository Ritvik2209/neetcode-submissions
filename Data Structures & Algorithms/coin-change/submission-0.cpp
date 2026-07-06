class Solution {
public:

    vector<vector<int>> dp;

    int solve(int x, int ind, vector<int>& coins)
    {
        if(x == 0)
            return 0;

        if(ind < 0)   return 1e9;
        if(dp[ind][x] != -1)return dp[ind][x];
        int notPick = solve(x, ind-1, coins);
        int pick = 1e9;
        if(coins[ind] <= x)
            pick = 1 + solve(x-coins[ind], ind, coins);
        return dp[ind][x] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        dp.assign(n, vector<int>(amount+1, -1));
        int ans = solve(amount, n-1, coins);
        return (ans >= 1e9) ? -1 : ans;
    }
};