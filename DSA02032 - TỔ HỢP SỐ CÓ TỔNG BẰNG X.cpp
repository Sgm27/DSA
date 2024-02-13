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
vi cur;
int n,s,a[100];
vector<vi> ans;
void Try(int idx,int cur_sum)
{
    if (idx == n+1) return;
    if (cur_sum == 0)
    {
        ans.push_back(cur);
        return;
    }
    if (cur_sum - a[idx] >= 0)
    {
        cur.push_back(a[idx]);
        Try(idx,cur_sum - a[idx]);
        cur.pop_back();
    }
    Try(idx+1,cur_sum);
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
        ans.clear();
        cin>>n>>s;
        FOR(i,1,n) cin>>a[i];
        Try(1,s);
        if (ans.size())
        {
            cout<<ans.size()<<" ";
            for (auto it : ans)
            {
                cout<<"{";
                for (int i=0;i<it.size()-1;i++) cout<<it[i]<<" ";
                cout<<it.back()<<"}";
                cout<<" ";
            }
            cout<<"\n";
        }
        else cout<<"-1\n";
    }
}
