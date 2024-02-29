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
        int n; cin>>n;	
        vi a(n);
        FOR(i,0,n-1) cin>>a[i];
        vi cur = a;
        vector<vi> ans;
        while (cur.size())
        {
            ans.push_back(cur);
            vi nxt;
            FOR(i,1,cur.size()-1)
                nxt.push_back(cur[i] + cur[i-1]);
            cur = nxt;
        }
        reverse(ALL(ans));
        for (auto it : ans)
        {
            cout<<"[";
            for (int i=0;i<it.size()-1;i++) cout<<it[i]<<" ";
            cout<<it.back()<<"] ";
        }
        cout<<"\n";
    }
}