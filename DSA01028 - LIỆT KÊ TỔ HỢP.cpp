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
int n,k;
int x[25];
vi a;
void update()
{
    FOR(i,1,k)
        cout<<a[x[i]]<<" ";
    cout<<"\n";
}
void Try(int i)
{
    FOR(j,x[i-1]+1,n-k+i)
    {
        x[i] = j;
        if (i == k) update();
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
    cin>>n>>k;
    map<int,int> mark;
    a.push_back(0);
    FOR(i,1,n)
    {
        int x; cin>>x;
        if (mark[x]) continue;
        mark[x] = 1;
        a.push_back(x);
    }
    sort(NALL(a));
    n = a.size() - 1;
    Try(1);
}
