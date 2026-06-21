class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l=1,r=1e9,mid=0,pos=-1;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        int sum=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]>mid) sum+=(piles[i]/mid) +1;
                else sum+=1;
        }
        if(sum>h)l=mid+1;
        else{
            pos=mid;
            r=mid-1;
        }

    }
    return pos;
    }
};
