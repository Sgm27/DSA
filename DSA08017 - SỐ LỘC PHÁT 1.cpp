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
    q.push("6");
    q.push("8");
    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        if (cur.size() >= 16) continue;
        ans.push_back(stoll(cur));
        q.push(cur + "6");
        q.push(cur + "8");
    }
}
int Pow(int a, int n)
{
    if (!n) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n/2);
    tmp=tmp*tmp;
    if (n%2) tmp=tmp*a;
    return tmp;
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
        int n; cin>>n;
        auto fi = lower_bound(ALL(ans), Pow(10, n-1));
        fi = ans.begin();
        auto la = upper_bound(ALL(ans), Pow(10, n));
        // cout<<la - fi<<"\n";
        vi tmp;
        for (auto it = fi;it != la; it++) tmp.push_back(*it);
        reverse(ALL(tmp));
        for (int x : tmp) cout<<x<<" ";
        cout<<"\n";
    }
}
