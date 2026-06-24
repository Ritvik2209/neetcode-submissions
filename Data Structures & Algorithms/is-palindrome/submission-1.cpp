class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            if((s[i]>='A' && s[i]<='Z') ||(s[i]>='a' && s[i]<='z') ||(s[i]>='0' && s[i]<='9'))temp.push_back(s[i]);
            
        }
        int l=0,r=(int)temp.size()-1;
        while(l<=r)
        {
            char left=tolower(temp[l]);
            char right=tolower(temp[r]);
            if(left==right)
            {
                l++;
                r--;

            }
            else return false;
        }
        return true;
    }
};
