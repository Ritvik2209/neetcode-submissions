class Solution {
public:
    vector<vector<int>> dp;
    int offset;

    int solve(int ind, int sum, vector<int>& nums, int target)
    {
        if(ind < 0)
        {
            return (sum == target);
        }

        if(dp[ind][sum + offset] != -1)
            return dp[ind][sum + offset];

        int add = solve(ind - 1, sum + nums[ind], nums, target);
        int sub = solve(ind - 1, sum - nums[ind], nums, target);

        return dp[ind][sum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();

        int totalSum = 0;
        for(int x : nums)
            totalSum += x;

        if(target > totalSum || target < -totalSum)
            return 0;

        offset = totalSum;

        dp.assign(n, vector<int>(2 * totalSum + 1, -1));

        return solve(n - 1, 0, nums, target);
    }
};