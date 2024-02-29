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
// #define int long long
#define vi vector<int>
#define pii pair<int,int>
// const int MOD=1e9+7,INF=4e18;
#define maxn 
inline int solve(int n)
{
    unordered_map<int,int> mark;
    mark[n] = 1;
    if (n == 1)
        return 0;
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front();
        // deb(cur, mark[cur])
        q.pop();
        int Sqrt = sqrt(cur);
        FOR(i,2,Sqrt)
            if (cur % i == 0)
            {
                int maxx = cur / i;
                if (mark[maxx] == 0)
                {
                    mark[maxx] = mark[cur] + 1;
                    q.push(maxx);
                }
            }
        if (cur == 2)
            return mark[cur];
        if (mark[cur - 1] == 0) 
        {
            mark[cur - 1] = mark[cur] + 1;
            q.push(cur - 1);
        }
    }
    return -1; // vscode base
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
