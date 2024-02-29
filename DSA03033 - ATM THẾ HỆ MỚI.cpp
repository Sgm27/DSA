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
int n,c,f[20],g[20];
// f[i] : minimum number of banknote to get value i
// g[i] : number of way to get f[i]
const int a[] = {1,2,3,5};
vi banknote;
void init()
{
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;
    FOR(i,0,3)
        FOR(j,a[i],19)
            if (f[j] > f[j-a[i]] + 1)
            {
                f[j] = f[j-a[i]] + 1;
                g[j] = g[j-a[i]];
            }
            else
            if (f[j] == f[j-a[i]] + 1)
                g[j] += g[j-a[i]];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>c;
        if (n % 1000)
        {
            cout<<"0\n";
            continue;
        }   	
        n /= 1000;
        if (n < 10)
        {
            cout<<f[n]<<" "<<g[n]<<"\n";
            continue;
        }
        pii ans = {0, 1};
        // ans.fi : number of banknote in optimal way
        // ans.se : number of optimal way
        while (c--)
        {
            if (!n) break;
            int cur_digit = n % 10;
            n /= 10;
            ans.first += f[cur_digit];
            ans.second *= g[cur_digit];
        }
        if (n < 10)
        {
            ans.first += f[n];
            ans.second *= g[n];
        }
        else 
        {
            ans.first += n / 5;
            n -= n/5 * 5;
            ans.first--;
            n += 5;
            ans.first += f[n];
            ans.second *= g[n];
        }
        cout<<ans.first<<" "<<ans.second<<"\n";
    }
}
