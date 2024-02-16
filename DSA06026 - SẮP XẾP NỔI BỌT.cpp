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
    int n; cin>>n;
    vi a(n+1);
    vector<vi> ans;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n)
    {
        bool change = false;
        FOR(j,1,n-1)
            if (a[j] > a[j+1]) 
            {
                swap(a[j], a[j+1]);
                change = true;
            }
        if (change) ans.push_back(a);
    }
    FOR(i,0,ans.size()-1)
    {
        cout<<"Buoc "<<i+1<<": ";
        FOR(ii,1,n) cout<<ans[i][ii]<<" ";
        cout<<"\n";
    }
}
