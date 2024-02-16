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

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    stack<char> cur, wait;
    string s; cin>>s;
    for (char c : s)
    {
        // deb(c)
        if (c != '-' && c != '<' && c != '>') cur.push(c);
        else
        {
            if (c == '-' && cur.size()) cur.pop();
            else
            if (c == '<' && cur.size()) 
            {
                wait.push(cur.top());
                cur.pop();
            }
            else
            if (c == '>' && wait.size())
            {
                cur.push(wait.top());
                wait.pop();
            }
        }
    }
    // deb(cur)
    string ans;
    while (!cur.empty()) 
    {
        ans.push_back(cur.top());
        cur.pop();
    }
    reverse(ALL(ans));
    // deb(wait)
    while (!wait.empty()) 
    {
        ans.push_back(wait.top());
        wait.pop();
    }
    cout<<ans;
}

