class Solution {
public:
vector<int>dp;
int solve(int x,vector<int>&cost)
{
    if(x==0 || x==1)return 0;
    if(x<0)return 0;
    if(dp[x]!=-1)return dp[x];
    return dp[x]=min(solve(x-1,cost)+cost[x-1],solve(x-2,cost)+cost[x-2]);

}
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        dp.assign(n+1,-1);
        return solve(n,cost);
    }
};
