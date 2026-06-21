class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int ans=INT_MIN;
       int l=0,r=n-1;
       while(l<r)
       {
        int val=min(heights[l],heights[r]);
        ans=max(ans,val*(r-l));
        if(heights[l]<=heights[r])l++;
        else r--;
       }
       return ans;
    }
};
