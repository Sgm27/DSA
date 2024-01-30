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
#define maxn 1000000
vi ans;
void gen_ans()
{
    FOR(i,1,maxn)
        ans.push_back(i * i * i);
}
bool check(int a,int b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);
    int idx = 0;
    FOR(i,0,s2.length()-1)
    {
        if (s2[i] == s1[idx]) idx++;
        if (idx == s1.length()) return 1;
    }
    return 0;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    gen_ans();
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;
        int fi = lower_bound(ALL(ans), n) - ans.begin();
        int res = -1;
        FOD(i,fi,0)
        {
            if (check(ans[i], n)) 
            {
                res = ans[i];
                break;
            }
        }
        cout<<res<<"\n";
    }
}