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
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
vector<string> a;
vector<string> cur;
vector<vector<string>> ans;
int n,k;
void Try(int i)
{
    FOR(j,0,1)
    {
        if (j==1)
            cur.push_back(a[i]);
        if (i == a.size() - 1)
        {
            if (cur.size() == k)
            {
                ans.push_back(cur);
            }
        }
        else
        Try(i+1);
        if (j==1) 
            cur.pop_back();
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc=1;
    while (tc--)
    {
        cin>>n>>k;
        FOR(i,1,n) 
        {
            string s; cin>>s;
            a.push_back(s);
        }
        sort(ALL(a));
        a.resize(unique(ALL(a)) - a.begin());
        Try(0);
        sort(ALL(ans));
        for (auto it : ans)
        {
            for (auto i : it) cout<<i<<" ";
            cout<<"\n";
        }
    }
}
