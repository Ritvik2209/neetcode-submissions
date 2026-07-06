class Solution {
public:
vector<int>dp;
int solve(int x,vector<int>&nums)
{
if(x==0)return nums[x];
if(x<0)return 0;
if(dp[x]!=-1)return dp[x];
int pick=nums[x]+solve(x-2,nums);
int n_pick=solve(x-1,nums);
return dp[x]=max(pick,n_pick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,-1);
        return solve(n-1,nums);
    }
};
