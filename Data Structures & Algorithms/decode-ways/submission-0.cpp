class Solution {
public:
    vector<int> dp;

    int solve(int i, string &s)
    {
        if(i == s.length())     return 1;

        if(s[i] == '0')
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans1 = solve(i + 1, s);

        int ans2 = 0;

        if(i + 1 < s.length())
        {
            int val = stoi(s.substr(i, 2));

            if(val >= 10 && val <= 26)
                ans2 = solve(i + 2, s);
        }

        return dp[i] = ans1 + ans2;
    }

    int numDecodings(string s)
    {
        int n = s.length();

        dp.assign(n, -1);

        return solve(0, s);
    }
};