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
int n,s,a[25],sum;
vi cur;
bool ans;
void Try(int i)
{
    for (int j=cur[i-1];j<=n;j++)
        if (sum + a[j] <= s)
        {
            sum += a[j];
            cur.push_back(j);
            if (sum == s)
            {
                ans = true;
                cout<<"[";
                FOR(k,1,cur.size()-2) cout<<a[cur[k]]<<" ";
                cout<<a[cur.back()]<<"]";
            }
            else
                Try(i+1);
            sum -= a[j];
            cur.pop_back();
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
        cur.clear();
        sum = 0;
        ans = false;
        cin>>n>>s;
        FOR(i,1,n) cin>>a[i];
        sort(a+1,a+1+n);
        cur.push_back(1);
        Try(1);
        if (ans == false) cout<<"-1";
        cout<<"\n";
    }
}
