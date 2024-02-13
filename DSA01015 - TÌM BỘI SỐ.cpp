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
vi ans;
void init()
{
    queue<int> q;
    q.push(9);
    while (!q.empty())
    {
        int cur = q.front();
        ans.push_back(cur);
        q.pop();
        if (cur * 10 < INF) q.push(cur * 10);
        if (cur * 10 + 9 < INF) q.push(cur * 10 + 9);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;
        for (int x : ans)
            if (x % n == 0)
            {
                cout<<x<<"\n";
                break;
            }
    }
}