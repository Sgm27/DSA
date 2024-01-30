#include<bits/stdc++.h>
#ifdef DS
    #include "debug.h"
#else 
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
struct Fenwick2d
{
    vector <vector<int>> node,bit;
    int sz;
    void init(int n)
    {
        sz=n;
        node.resize(n+1);
        bit.resize(n+1);
    }
    void compressNode()
    {
        for(int i=1; i<=sz; i++)
        {
            sort(node[i].begin(),node[i].end());
            node[i].erase(unique(node[i].begin(),node[i].end()),node[i].end());
            bit[i].resize(node[i].size()+1);
        }
    }
    void fakeUpdate(int x, int y)
    {
        for(; x<=sz; x+=x&-x)node[x].push_back(y);
    }
    void fakeGet(int x, int y)
    {
        for(; x>0; x-=x&-x)node[x].push_back(y);
    }
    void update(int x, int yy, int val)
    {
        for(; x<=sz; x+=x&-x)
        {
            for(int y=lower_bound(node[x].begin(),node[x].end(),yy)-node[x].begin()+1; y<=node[x].size(); y+=y&-y)
            {
                bit[x][y-1] = max(bit[x][y-1], val);
            }
        }
    }
    int get(int x, int yy)
    {
        int res=0;
        for(; x>0; x-=x&-x)
        {
            for(int y=lower_bound(node[x].begin(),node[x].end(),yy)-node[x].begin()+1; y>0; y-=y&-y)
            {
                res = max(res, bit[x][y-1]);
            }
        }
        return res;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<pii> point;
    vi compressX, compressY;
    int n; cin>>n;
    FOR(i,1,n)
    {
        int x,y; cin>>x>>y;
        point.push_back({x,y});   
        compressX.push_back(x);
        compressY.push_back(y);
    }
    sort(ALL(compressX));
    compressX.resize(unique(ALL(compressX)) - compressX.begin());
    sort(ALL(compressY));
    compressY.resize(unique(ALL(compressY)) - compressY.begin());
    for (auto &[x,y] : point)
    {
        x = lower_bound(ALL(compressX), x) - compressX.begin() + 1;
        y = lower_bound(ALL(compressY), y) - compressY.begin() + 1;
    }
    Fenwick2d fw;
    fw.init(compressX.size());
    for (auto [x,y] : point)
    {
        fw.fakeGet(x-1,y-1);
        fw.fakeUpdate(x,y);
    }
    fw.compressNode();
    int ans = -INF;
    for (auto [x,y] : point)
    {
        int cur = fw.get(x-1,y-1) + 1;
        ans = max(ans, cur);
        fw.update(x,y,cur);
    }
    cout<<ans;
}