class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>ans(n,0);
        ans[n-1]=true;
        for(int i=n-2;i>=0;i--)
        {
            bool flag=false;
            for(int j=i;j<i+nums[i]+1;j++)
            {
                if(j>=n)continue;
                if(ans[j])
                {
                    flag=true;
                    break;
                }
            }
            if(flag)ans[i]=true;
        }
        if(ans[0])return true;
        return false;        
    }
};
