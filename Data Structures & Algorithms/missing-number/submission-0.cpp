class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int req_sum=(n*(n+1))/2;
        for(int i=0;i<(int)nums.size();i++)sum+=nums[i];
        return req_sum-sum;

    }
};
