class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>ans;
        map<int,int>mp;
        set<int>st;
        for(int i=0;i<(int)nums.size();i++)mp[nums[i]]++;
        for(int i=0;i<n;i++)
        {
            if(st.find(nums[i])==st.end())
            {
                ans.push_back({mp[nums[i]],nums[i]});
                st.insert(nums[i]);
            }
        }
        sort(ans.rbegin(),ans.rend());
vector<int>f_ans;
        for(int i=0;i<k;i++)
        {
            f_ans.push_back(ans[i].second);

        }
        return f_ans;
        
    }
};
