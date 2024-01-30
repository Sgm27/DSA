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
int x[5],a[6],n = 5;
bool check()
{
    int cur = a[1];
    FOR(i,1,4)
    {
        if (x[i] == 1) cur += a[i+1];
        if (x[i] == 2) cur -= a[i+1];
        if (x[i] == 3) cur *= a[i+1];
    } 
    return cur == 23;
}
bool ans;
void Try(int i)
{
    if (i == n)
    {
        if (check())
        {
            ans = true;
            exit;
        }
        return;  
    } 
    FOR(j,1,3)
    {
        x[i] = j;
        Try(i+1);
    }
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
        ans = false;
        FOR(i,1,n) cin>>a[i];
        int aa[n+1];
        FOR(i,1,n) aa[i] = a[i];
        vi b = {1,2,3,4,5};
        do{
            // deb(b)
            FOR(i,1,n)
                a[i] = aa[b[i-1]];
            Try(1);
            if (ans == true)
            {
                cout<<"YES\n";
                break;
            }
        }
        while (next_permutation(ALL(b)));
        if (!ans)
            cout<<"NO\n";
    }
}