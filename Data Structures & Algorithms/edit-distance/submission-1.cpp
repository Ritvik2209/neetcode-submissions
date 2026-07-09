class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,string &s1,string &s2)
    {
        if(i == s1.length())
            return s2.length() - j;

        if(j == s2.length())
            return s1.length() - i;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=solve(i+1,j+1,s1,s2);
        return dp[i][j]=min(1+solve(i+1,j+1,s1,s2),min(1+solve(i+1,j,s1,s2),1+solve(i,j+1,s1,s2)));

    }
    int minDistance(string word1, string word2) {

        int n=word1.length();
        int m=word2.length();
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,word1,word2);

    }
};
