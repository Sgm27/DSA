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
vi cur;
int n,a[15],k,sum;
vector<vi> ans;
void Try(int i)
{
    FOR(j,0,1)
    {
        if (j) 
        {
            sum += a[i];
            cur.push_back(a[i]);
        }
        if (i == n)
        {
            if (sum == k)
                ans.push_back(cur);
        }
        else Try(i+1);
        if (j) 
        {
            sum -= a[i];
            cur.pop_back();
        }
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
        sum = 0;
        ans.clear(), cur.clear();
        cin>>n>>k;
        FOR(i,1,n) cin>>a[i];
        sort(a+1,a+1+n);
        Try(1);
        if (ans.size() == 0)
        {
            cout<<"-1\n";
            continue;
        }
        sort(ALL(ans));
        for (auto it : ans)
        {
            cout<<"[";
            for (int i=0;i<it.size()-1;i++) cout<<it[i]<<" ";
            cout<<it.back()<<"] ";
        }
        cout<<"\n";
    }
}
