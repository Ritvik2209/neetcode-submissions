class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        set<int>st;
        for(int i=0;i<n;i++)st.insert(nums[i]);
        vector<int>temp;
         for(auto it:st)temp.push_back(it);
        sort(temp.begin(),temp.end());
        int len=1,ans=INT_MIN;
        for(int i=1;i<(int)temp.size();i++)
        {
            if(temp[i]-temp[i-1]==1)len++;
            else
            {
                ans=max(ans,len);
                len=1;

            }
        }
        ans=max(ans,len);
        return ans;
    }
};
