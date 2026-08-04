class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        vector<int>c;
        while(i<n && j<m)
        {
            if(nums1[i]<=nums2[j])
            {
                 c.push_back(nums1[i]);
                 i++;
            }
            else 
            {
                c.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n)

        {
            c.push_back(nums1[i]);
            i++;
        }
        while(j<m)
        {
            c.push_back(nums2[j]);
            j++;
        }
         
        int val=(n+m);
        int curr=val/2;
        if(val%2)return (double)c[curr];
        return (double)(c[curr]+c[curr-1])/2;
       

        
    }
};
