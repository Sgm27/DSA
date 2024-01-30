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
vector<vi> ans;
int x[15],n,k,mark[15],a[15][15];
int sum;
void Try(int i)
{
    FOR(j,1,n)
        if (mark[j] == 0)
        {
            sum += a[i][j];
            x[i] = j;
            mark[j] = 1;
            if (i == n)
            {
                if (sum == k)
                {
                    vi tmp(x+1,x+1+n);
                    ans.push_back(tmp);
                }
            }
            else
                Try(i+1);
            sum -= a[i][j];
            mark[j] = 0;
        }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    FOR(i,1,n)
        FOR(j,1,n) cin>>a[i][j];
    Try(1);
    cout<<ans.size()<<"\n";
    for (auto it : ans)
    {
        for (auto it2 : it) cout<<it2<<" ";
        cout<<"\n";
    }
}
