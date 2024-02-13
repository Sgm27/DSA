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
int n,a[20];
vi cur;
vector<vi> ans;
void Try(int i,int cur_sum)
{
    if (i == n+1)
    {
        if (cur_sum & 1)
            ans.push_back(cur);
        return;
    }
    cur.push_back(a[i]);
    Try(i+1,cur_sum + a[i]);
    cur.pop_back();
    Try(i+1,cur_sum);
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
        cin>>n;	
        FOR(i,1,n) cin>>a[i];
        sort(a+1,a+1+n,greater<int>());
        Try(1,0);
        sort(ALL(ans));
        for (auto it : ans)
        {
            for (auto x : it) cout<<x<<" ";
            cout<<"\n";
        }
    }
}
