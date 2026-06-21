class Solution {
public:
int check(int x)
{
    int ans=0;
    for(int i=0;i<32;i++)
    {
        if((1<<i)&x)ans++;
    }
    return ans;
}
    vector<int> countBits(int n) {
        vector<int>answer(n+1,0);
        for(int i=0;i<=n;i++)answer[i]=check(i);
        return answer;
        
    }
};
