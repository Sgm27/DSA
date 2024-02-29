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
vi ans;
void init()
{
    queue<string> q;
    FOR(i,1,5) q.push(to_string(i));
    auto check = [](string s) -> bool
    {
        unordered_map<char,int> mark;
        for (char c : s)
            if (mark[c]) return false;
            else mark[c] = 1;
        return true;
    };
    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        if (!check(cur)) continue;
        int num = stoll(cur);
        if (num <= 1e5) 
        {
            ans.push_back(num);
            FOR(i,0,5)
                q.push(cur + string(1,i + '0'));
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
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int l,r; cin>>l>>r;
        auto it1 = lower_bound(ALL(ans), l);
        auto it2 = upper_bound(ALL(ans), r);
        cout<<it2 - it1<<"\n";
    }
}
