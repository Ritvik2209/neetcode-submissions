class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if((s[i]!="+") && (s[i]!="-") && (s[i]!="*") &&(s[i]!="/") )
            {
                int x=stoi(s[i]);
                st.push(x);
            }
            else
            {
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                if(s[i]=="+")st.push(t1+t2);
                 if(s[i]=="-")st.push(t2-t1);
                  if(s[i]=="*")st.push(t1*t2);
                   if(s[i]=="/")st.push(t2/t1);
               
            }
        }
        return st.top();
    }
};
