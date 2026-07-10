class Solution {
public:
vector<vector<int>>dp;
int solve(int i,int j,string &s1,string &s2)
{
    if(i>=s1.length())return 0;
    if(j>=s2.length())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j])return dp[i][j]=1+solve(i+1,j+1,s1,s2);
    return dp[i][j]=max(solve(i+1,j,s1,s2),solve(i,j+1,s1,s2));
}
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,s1,s2);
    }
};
