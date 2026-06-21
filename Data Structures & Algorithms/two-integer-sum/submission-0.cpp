class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        bool flag=false;
vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(flag==true)break;
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    flag=true;
                    break;
                }
            }
        }
        return ans;
    }
};
