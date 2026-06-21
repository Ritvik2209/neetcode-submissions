class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        bool flag=true;
        for(int i=0;i<(int)s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')st.push(s[i]);
            else
            {
                if(st.size()>0)
                {

                if(s[i]==')')
                {
                    if(st.top()=='(')st.pop();
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                else if(s[i]=='}')
                {
                  if(st.top()=='{')st.pop();  
                  else
                    {
                        flag=false;
                        break;
                    } 
                }
                else if(s[i]==']')
                {
                     if(st.top()=='[')st.pop();
                     else
                    {
                        flag=false;
                        break;
                    }
                }
                }
                else

                {
                    flag=false;
                    break;
                }
                
            }
        }
        if(st.size()>0 || flag==false)return false;
        return true;
        
    }
};
