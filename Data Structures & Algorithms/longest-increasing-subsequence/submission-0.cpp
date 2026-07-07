class Solution {
public:
vector<vector<int>>dp;
int solve(int i,int j,vector<int>&nums)
{
    if(i>=nums.size())return 0;
    if(dp[i][j+1]!=-1)return dp[i][j+1];
    int n_pick=solve(i+1,j,nums);
    int pick=0;
    if( j==-1 || nums[i]>nums[j] )pick=1+solve(i+1,i,nums);
    return dp[i][j+1]=max(pick,n_pick);
}
 int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
        dp.assign(n,vector<int>(n,-1));
        return solve(0,-1,nums);
    }
};
