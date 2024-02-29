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
int n,a[25];
vector<string> ans;
void Try(int i,string cur = "",int cnt = 0)
{
    FOR(j,i+1,n)
        if (a[j] > a[i])
        {
            if (cnt) ans.push_back(cur + to_string(a[j]) + " ");
            Try(j, cur + to_string(a[j]) + " ", cnt + 1);
        }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    memset(a, -1, sizeof a);
    FOR(i,1,n) 
        cin>>a[i];
    Try(0);
    sort(ALL(ans));
    for (auto it : ans) 
        cout<<it<<"\n";
}
