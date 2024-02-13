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
char pivot, x[25];
int n;
void Try(int i)
{
    for (char c = (char)(x[i-1]); c <= (char)(pivot); c++)
    {
        x[i] = c;
        if (i == n)
        {
            FOR(ii,1,n) cout<<x[ii];
            cout<<"\n";
        }
        else Try(i+1);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>pivot>>n;
    x[0] = 'A';
    Try(1);
}
