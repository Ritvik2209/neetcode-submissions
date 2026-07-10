class Solution {
public:
vector<vector<int>>dp;
bool solve(int i,int j,int temp,vector<int>&nums)
{
    if(i<0)return false;
    if(dp[i][j]!=-1)return dp[i][j];
    if(temp-j==j)return dp[i][j]=true;
    return dp[i][j]=solve(i-1,j-nums[i],temp,nums) ||solve(i-1,j,temp,nums);


}
    bool canPartition(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++)sum+=nums[i];   
    if(sum%2==1 || n==1)return false;
    dp.assign(n,vector<int>(sum+1,-1)); 
    return solve(n-1,sum,sum,nums);
    }
};
