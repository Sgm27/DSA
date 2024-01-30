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
map<int,int> mark;
int n,s,a[35],cnt,cur_sum,ans;
void Try(int i,int end_idx,int type)
{
    FOR(j,0,1)
    {
        cur_sum += a[i] * j;
        cnt += j;
        if (i == end_idx)
        {
            if (type == 0)
            {
                if (cur_sum == s)
                    ans = min(ans, cnt);
                if (!mark[cur_sum]) mark[cur_sum] = cnt;
                else mark[cur_sum] = min(mark[cur_sum], cnt);
            }
            else
            {
                if (cur_sum == s) 
                    ans = min(ans, cnt);
                if (mark[s - cur_sum])
                    ans = min(ans, mark[s - cur_sum] + cnt);
            }
        }
        else 
            Try(i+1,end_idx,type);
        cur_sum -= a[i] * j;
        cnt -= j;
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
        mark.clear();
        cin>>n>>s;
        cur_sum = cnt = 0;
        ans = INF;
        FOR(i,1,n) cin>>a[i];
        Try(1, n/2, 0);
        Try(n/2 + n%2, n, 1);
        cout<<(ans == INF ? -1 : ans)<<"\n";
    }
}