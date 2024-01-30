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
const int MOD=1e9+7,INF=4e18,base=13;
#define maxn 100005
int p[maxn];
string s;
struct Node{
    int lhash,rhash,len;
    Node()
    {
        lhash = rhash = len = 0;
    }
};
Node makeNode(int _lhash,int _rhash,int _len)
{
    Node ans;
    ans.lhash = _lhash;
    ans.rhash = _rhash;
    ans.len = _len;
    return ans;
}
Node Merge(Node l,Node r)
{
    Node ans;
    ans.lhash = (l.lhash * p[r.len] + r.lhash) % MOD;
    ans.rhash = (r.rhash * p[l.len] + l.rhash) % MOD;
    ans.len = l.len + r.len;
    return ans;
}
struct Segment_Tree{
    vector<Node> st;
    Segment_Tree (int _sz)
    {
        st.resize(_sz << 2);
    }
    void build(int id,int l,int r)
    {
        if (l == r) 
            return st[id] = makeNode(s[l]-'0'+1,s[l]-'0'+1,1), void(); // base Node
        int m = l+r >> 1;
        build(id << 1,l,m);
        build(id << 1 | 1,m+1,r);
        st[id] = Merge(st[id << 1], st[id << 1 | 1]);
    }
    void update(int id,int l,int r,int pos)
    {
        if (l > pos || r < pos) 
            return;
        if (l == r)
            return st[id] = makeNode(s[pos]-'0'+1,s[pos]-'0'+1,1), void();
        int m = l+r >> 1;
        update(id << 1,l,m,pos);
        update(id << 1 | 1,m+1,r,pos);
        st[id] = Merge(st[id << 1], st[id << 1 | 1]);
    }
    Node get(int id,int l,int r,int u,int v)
    {
        if (r < u || l > v) return Node();
        if (l >= u && r <= v) return st[id];
        int m = l+r >> 1;
        return Merge(get(id << 1,l,m,u,v), get(id << 1 | 1,m+1,r,u,v));
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    p[0] = 1;
    FOR(i,1,maxn-5) p[i] = (p[i-1] * base) % MOD;
    cin>>s;
    int n = s.length();
    s = " " + s;
    Segment_Tree ST(n+1);
    ST.build(1,1,n);
    int q; cin>>q;
    while (q--)
    {
        char type; cin>>type;
        if (type == 'q')
        {
            int l,r; cin>>l>>r;
            Node ans = ST.get(1,1,n,l,r);
            cout<<(ans.lhash == ans.rhash ? "YES\n" : "NO\n");
        }
        else
        {
            int pos,val; cin>>pos>>val;
            s[pos] = '0' + val;
            ST.update(1,1,n,pos);
        }
    }
}
