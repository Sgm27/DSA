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
        vi a(n+1);
        multiset<int> ms[3];
        int mod = 0;
        FOR(i,1,n)
        {
            cin>>a[i];
            ms[a[i] % 3].insert(a[i]);
            mod = (mod + a[i] % 3) %3;
        }
        map<int,int> del;
        sort(NALL(a));
        reverse(NALL(a));
        bool ans = false;
        if (mod == 1)
        {
            if (ms[1].size()) 
            {
                del[*ms[1].begin()]++;
            }
            else
            {
                if (ms[2].size() >= 2)
                {
                    del[*ms[2].begin()]++;
                    ms[2].erase(ms[2].begin());
                    del[*ms[2].begin()]++;
                }
            }
        }
        if (mod == 2)
        {
            if (ms[2].size())
            {
                del[*ms[2].begin()]++;
            }
            else
            {
                if (ms[1].size() >= 2)
                {
                    del[*ms[1].begin()]++;
                    ms[1].erase(ms[1].begin());
                    del[*ms[1].begin()]++;
                }
            }
        }
        FOR(i,1,n)
            if (del[a[i]]) del[a[i]]--;
            else 
            {
                cout<<a[i];
                ans = true;
            }
        if (!ans) cout<<"-1";
        cout<<"\n";
    }
}
