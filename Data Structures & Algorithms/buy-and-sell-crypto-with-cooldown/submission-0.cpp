class Solution {
public:
vector<vector<int>>dp;
int solve(int i,int j,vector<int>&prices)
{
    if(i>=prices.size())return 0;
    if(dp[i][j+1]!=-1)return dp[i][j+1];
    if(j>=0)//we have a coin
    {
        int sell=prices[i]-prices[j]+solve(i+2,-1,prices);
        int n_sell=solve(i+1,j,prices);
        return dp[i][j+1]=max(sell,n_sell);
    }
    //we don't have a coin
    int buy=solve(i+1,i,prices);
    int n_buy=solve(i+1,-1,prices);
    return dp[i][j+1]=max(buy,n_buy);

}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n,vector<int>(n+1,-1));
        return solve(0,-1,prices);
    }
};
