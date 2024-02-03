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
        int d; cin>>d;	
        string s; cin>>s;
        map<char,int> mark;
        for (char c : s) mark[c]++;
        vector<pair<char,int>> a(ALL(mark));
        sort(ALL(a), [](pair<char,int> a, pair<char,int> b)
        {
            return a.second > b.second;
        });
        vi dd(s.length(), 0);
        int idx = 0;
        bool ans = true;
        for (auto it : a)
        {
            while (dd[idx]) idx++;
            int cnt = it.second, cur = idx;
            while (cnt--) 
            {
                if (dd[cur] || cur >= s.length())  
                {
                    ans = false;
                    break;
                }
                dd[cur] = 1;
                cur += d;
            }
            if (ans == false) break;
        }
        cout<<(ans ? 1 : -1)<<"\n";
    }
}