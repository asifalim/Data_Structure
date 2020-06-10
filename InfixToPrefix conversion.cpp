#include<bits/stdc++.h>
using namespace std;
int p(char c)
{
    if(c=='^')
        return 3;
    else if(c=='/' || c=='*')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return -1;
}
void intopre(string s)
{
    int i,j;
    stack<char>st;
    for(i=0;i<s.size();i++)
    {
        if(isalpha(s[i]))
            cout<<s[i];
        else if(s[i]==')')
        {
            while(st.top()!='(')
            {
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
           if(st.empty()==true)
           {
               st.push(s[i]);
           }
           else
           {
               if(s[i]=='(' || st.top()=='(' || p(s[i])>p(st.top()))
                    st.push(s[i]);
               else
               {
                   while(st.empty()==false && p(s[i])<=p(st.top()) && st.top()!='(')
                   {
                       cout<<st.top();
                       st.pop();
                   }
                   st.push(s[i]);
               }
           }
        }
    }
    while(st.empty()==false)
    {
        cout<<st.top();
        st.pop();
    }
}
int main()
{
    int t,n,i,j;
    cin>>t;
    while(t--)
    {
        string s,ss;
        cin>>s;
        intopre(s);
        cout<<endl;
    }
    return 0;
}
