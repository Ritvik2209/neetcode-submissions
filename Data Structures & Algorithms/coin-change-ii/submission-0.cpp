class Solution {
public:
vector<vector<int>>dp;
int solve(int ind,int x,vector<int>&coins)
{
    if(ind<0)
    {
        return 0;
    }
    if(x==0)return 1;
    if(dp[ind][x]!=-1)return dp[ind][x];
    int not_pick=solve(ind-1,x,coins);
    int pick=0;
    if(coins[ind]<=x)pick=solve(ind,x-coins[ind],coins);
    return dp[ind][x]=pick+not_pick;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins);
    }
};
