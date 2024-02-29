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
bool mod(string a,int m)
{
    int res = 0;
    for (char c : a)
        res = (res * 10 + (c - '0')) % m;
    return res == 0;
}
string solve(int n)
{
    queue<string> q;
    q.push("1");
    while (1)
    {
        string cur = q.front();
        q.pop();
        if (mod(cur, n)) return cur;
        q.push(cur + "0");
        q.push(cur + "1");
    }
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
        int n; cin>>n;
        cout<<solve(n)<<"\n";	
    }
}
