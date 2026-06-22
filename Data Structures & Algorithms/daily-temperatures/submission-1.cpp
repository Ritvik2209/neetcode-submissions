class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        int n=temp.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            int val=temp[i];
            while((!(st.empty())) && val>=temp[st.top()])
            {
                st.pop();
            }
            if(!(st.empty()))ans[i]=st.top()-i;
            st.push(i);

        }
        return ans;
    }
};
