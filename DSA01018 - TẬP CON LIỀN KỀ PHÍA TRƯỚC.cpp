
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
    int tc; cin>>tc;
    while (tc--)
    {
        int n,k; cin>>n>>k;
        vi a(k+1);
        FOR(i,1,k) cin>>a[i];	
        int pos = -1;
        FOD(i,k-1,1)
            if (a[i] != a[i+1] - 1)
            {
                pos = i+1;
                break;
            }
        if (pos == -1)
        {
            FOR(i,n-k+1,n) cout<<i<<" ";
            cout<<"\n";
        }
        else
        {
            a[pos]--;
            FOR(i,pos+1,k)  a[i] = n-k+i;
            FOR(i,1,k) cout<<a[i]<<" ";
            cout<<"\n";
        }
    }
}
