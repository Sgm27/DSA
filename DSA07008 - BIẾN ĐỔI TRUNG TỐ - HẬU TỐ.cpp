#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
int prio(char op)
{
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 3;
}
void process_op(stack<string> &res,char op)
{
    string r = res.top(); res.pop();
    string l = res.top(); res.pop();
    res.push(l+r+op);
}
void solve(string s)
{
    stack<string> res;
    stack<char> op;
    for (char c : s)
    {
        if (isalpha(c)) res.push(string(1, c));
        else
        {
            if (c == '(')
            {
                op.push('(');
                continue;
            }
            if (c == ')')
            {
                while (op.top() != '(')
                {
                    process_op(res, op.top());
                    op.pop();
                }
                op.pop();
            }
            else
            {
                while (!op.empty() && prio(op.top()) >= prio(c)) 
                {
                    process_op(res, op.top());
                    op.pop();
                }
                op.push(c);
            }
        }
    }
    while (!op.empty())
    {
        process_op(res, op.top());
        op.pop();
    }
    cout<<res.top()<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        string s; cin>>s;	
        solve(s);
    }
}
