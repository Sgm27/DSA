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
int n,k,sum,cnt;
vi a,x;
void Try(int i)
{
    for (int j=0;j<=1;j++)
    {
        sum += a[i] * j;
        x[i] = j;
        if (i == n-1)
        {
            if (sum == k)
            {
                FOR(l,0,n-1)
                if (x[l]) cout<<a[l]<<" ";
                cnt++;
                cout<<"\n";
            }
        }
        else
            Try(i+1);
        sum -= a[i] * j;
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
    a.resize(n);
    x.resize(n);
    for (int &x : a) cin>>x;
    Try(0);
    cout<<cnt;
}
