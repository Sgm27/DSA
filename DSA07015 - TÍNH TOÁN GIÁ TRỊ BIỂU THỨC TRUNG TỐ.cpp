#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int pre(char x)
{
    if (x=='(') return 0;
    if (x=='+' || x=='-') return 1;
    if (x=='*' || x=='/') return 2;
}
void process()
{
    stack<char> st;
    stack<ll> res;
    int i=0;
    while (i<s.length())
    {
        if (s[i]=='(') st.push(s[i]);
        else 
        if (s[i]==')')
        {
            while (!st.empty() && st.top()!='(')
            {
                ll op1=res.top(); res.pop();
                ll op2=res.top(); res.pop();
                ll x;
                if (st.top()=='+') x=op2+op1;
                else if (st.top()=='-') x=op2-op1;
                else if (st.top()=='*') x=op2*op1;
                else if (st.top()=='/') x=op2/op1;
                res.push(x);
                st.pop();
            }
            st.pop();
        }
        else
        if (isdigit(s[i]))
        {
            ll tmp=0;
            while (i<s.length() && isdigit(s[i])) tmp=tmp*10+(s[i++]-'0');
            res.push(tmp);
            continue;
        }
        else
        {
            while (!st.empty() && pre(st.top())>=pre(s[i]))
            {
                ll op1=res.top(); res.pop();
                ll op2=res.top(); res.pop();
                ll x;
                if (st.top()=='+') x=op2+op1;
                else if (st.top()=='-') x=op2-op1;
                else if (st.top()=='*') x=op2*op1;
                else if (st.top()=='/') x=op2/op1;
                res.push(x);
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ll op1=res.top(); res.pop();
        ll op2=res.top(); res.pop();
        ll x;
        if (st.top()=='+') x=op2+op1;
        else if (st.top()=='-') x=op2-op1;
        else if (st.top()=='*') x=op2*op1;
        else if (st.top()=='/') x=op2/op1;
        res.push(x);
        st.pop();
    }
    cout<<res.top()<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>s;	
        process();
    }
}

