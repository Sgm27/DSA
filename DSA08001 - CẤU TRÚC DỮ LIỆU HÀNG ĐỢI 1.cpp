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
        int q; cin>>q;
        deque<int> dq;
        while (q--)
        {
            int t; cin>>t;
            if (t == 1)
                cout<<dq.size()<<"\n";
            if (t == 2)
                cout<<(dq.empty() ? "YES\n" : "NO\n");
            if (t == 3)
            {
                int val; cin>>val;
                dq.push_back(val);
            }
            if (t == 4)
            {
                if (dq.empty()) continue;
                dq.pop_front();
            }
            if (t == 5)
                cout<<(dq.size() ? dq.front() : -1)<<"\n";
            if (t == 6)
                cout<<(dq.size() ? dq.back() : -1)<<"\n";
        }	
    }
}
