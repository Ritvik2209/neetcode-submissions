class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n=stones.size();
        for(int i=0;i<n;i++)
        {
            pq.push(stones[i]);
        }
        while(pq.size()!=1)
        {
            int t1=pq.top();
            pq.pop();
            int t2=pq.top();
            pq.pop();
            pq.push(abs(t1-t2));
        }
        return pq.top();
    }
};
