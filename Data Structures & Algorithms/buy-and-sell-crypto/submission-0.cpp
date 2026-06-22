class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<int>ans(n,0);
        int mx=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ans[i]=mx;
            mx=max(mx,a[i]);

        }
        int f_ans=0;
        for(int i=0;i<n;i++)f_ans=max(f_ans,ans[i]-a[i]);
        return f_ans;
    }
};
