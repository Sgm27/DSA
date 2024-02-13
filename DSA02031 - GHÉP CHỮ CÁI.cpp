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
    freopen("thu.ans","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    char c; cin>>c;
    auto check = [](vi a) -> bool
    {
        if (a.size() < 5)
        {
            if (a.front() != 'A' && a.back() != 'A') return false;
            return true;
        }
        FOR(i,1,a.size()-2)
            if (a[i] == 'A' || a[i] == 'E')
            {
                if (a[i-1] != 'A' && a[i+1] != 'A' && a[i-1] != 'E' && a[i+1] != 'E') return false;
            }
        return true;
    };
    vi a;
    deb(check({'E', 'D', 'C', 'B', 'A'}))
    FOR(i,'A',c) a.push_back(i);
    do {
        if (check(a))
        {
            for (char x : a) cout<<x;
            cout<<"\n";
        }
    }
    while (next_permutation(ALL(a)));
}
