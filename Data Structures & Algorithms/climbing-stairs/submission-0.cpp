class Solution {
public:
vector<int>dp;
int solve(int x)
{
    if(x==0)return 1;
    if(x<0)return 0;
    if(dp[x]!=-1)return dp[x];
    return dp[x]=solve(x-1)+solve(x-2);
}
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return solve(n);
        
    }
};
