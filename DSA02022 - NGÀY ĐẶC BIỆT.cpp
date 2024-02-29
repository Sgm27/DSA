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
int cur[50];
vector<vi> ans;
void update()
{
    if (cur[1] == 0 && cur[2] == 0) return;
    if (cur[3] == 0 && cur[4] == 0) return;
    if (cur[3] == 2) return;
    if (cur[5] == 0) return;
    vi tmp(cur+1,cur+9);
    ans.push_back(tmp);
}
void Try(int i)
{
    FOR(j,0,1)
    {
        if (j == 0) cur[i] = 0;
        else cur[i] = 2;
        if (i == 8) update();
        else Try(i+1);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    Try(1);
    sort(ALL(ans));
    for (auto it : ans)
    {
        cout<<it[0]<<it[1]<<"/"<<it[2]<<it[3]<<"/"<<it[4]<<it[5]<<it[6]<<it[7]<<"\n";
    }
}
