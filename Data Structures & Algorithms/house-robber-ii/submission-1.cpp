class Solution {
public:
vector<vector<int>>dp;
int solve(int i,bool j,vector<int>&nums)
{

    if(i<0)return 0;
    if(i==0)
    {
        if(j==0)return nums[0];
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int pick=nums[i]+solve(i-2,j,nums);
    int n_pick=solve(i-1,j,nums);
    return dp[i][j]=max(pick,n_pick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        dp.resize(n,vector<int>(2,-1));
        return max(solve(n-1,1,nums),+solve(n-2,0,nums));

        
    }
};
