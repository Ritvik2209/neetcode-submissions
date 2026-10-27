class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
    int ans=0;
    for(int i=0;i<(int)derived.size();i++)ans^=derived[i];
    return ans==0;
    }
};
