#include<bits/stdc++.h>
#ifdef DS
    #include "debug.h"
#else 
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 10000
bool is_prime[maxn+5];
vi nt, g[maxn];
bool check(int a,int b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);
    int res = 0;
    FOR(i,0,3)
        res += (s1[i] != s2[i]);
    return res == 1;
}
void init()
{
    FOR(i,2,maxn) 
        is_prime[i] = 1;
    FOR(i,2,sqrt(maxn))
        if (is_prime[i])
            for (int j = i*i; j<=maxn; j+=i) is_prime[j] = 0;
    FOR(i,1000,maxn)
        if (is_prime[i]) nt.push_back(i);
    for (int i=0;i<nt.size()-1;i++)
        for (int j=i+1;j<nt.size();j++)
            if (check(nt[i],nt[j])) 
            {
                g[nt[i]].push_back(nt[j]);
                g[nt[j]].push_back(nt[i]);
            }
}

void solve(int s,int t)
{
    unordered_map<int,int> mark;
    mark[s] = 1;
    if (s == t)
        return cout<<0, void();
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int nxt : g[cur])
            if (!mark[nxt])
            {
                if (nxt == t) 
                    return cout<<mark[cur], void();
                mark[nxt] = mark[cur] + 1;
                q.push(nxt);
            }
    }
}
signed main()
{
    #ifdef DS
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int s,t; cin>>s>>t;
        solve(s,t);
        cout<<"\n";
    }
}