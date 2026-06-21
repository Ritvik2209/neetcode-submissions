class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prod=1;
        vector<int>ans(n,0);
        int zero=0;
for(int i=0;i<n;i++)
{
    if(nums[i]==0)zero++;
   if(nums[i]!=0) prod*=nums[i];
}
if(zero==0)
{   
for(int i=0;i<n;i++)
{ 
    int temp=prod;
    temp/=nums[i];
    ans[i]=temp;
}
}
else if(zero==1)
{
    for(int i=0;i<n;i++)
    {
        if(nums[i]==0)ans[i]=prod;
    }
}
return ans;
    }
};
