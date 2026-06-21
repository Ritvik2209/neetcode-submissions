class Solution {
public:
    vector<int> twoSum(vector<int>& vec, int target) {
        int n=vec.size();
        int l=0,r=n-1;
        vector<int>ans;

        while(l<r)
        {
            int sum=vec[l]+vec[r];
            if(sum==target)
            {
                ans.push_back(l+1);
                ans.push_back(r+1);
            }
            if(sum<target)l++;
            else r--;
        }
        return ans;
        
    }
};
