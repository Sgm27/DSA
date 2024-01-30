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
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,base = 31;
#define maxn 100005 
string s,t,a[maxn];
int n;
long long p[15];
map<int,int> mark;
set<int> have;
int get_hash(string s)
{
    int ans = 0;
    for (char c : s)
        ans = ((1LL * ans * base) + (c - 'A' + 1)) % MOD;
    return ans; 
}
void bfs()
{
    queue<string> q;
    q.push(s);
    int hash_s = get_hash(s);
    mark[hash_s] = 1;
    have.erase(hash_s);
    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        FOR(i,0,cur.size()-1)
        {
            string nxt = cur;
            int hash_cur = get_hash(cur);
            for (char c = 'A';c<='Z';c++)
                if (c != cur[i])
                {
                    nxt[i] = c;
                    int hash_nxt = get_hash(nxt);
                    if (!have.count(hash_nxt)) continue;
                    have.erase(hash_nxt);
                    if (!mark[hash_nxt]) 
                    {
                        if (nxt == t) 
                            return cout<<mark[hash_cur] + 1<<"\n", void();
                        mark[hash_nxt] = mark[hash_cur] + 1;
                        q.push(nxt);
                    }
                }
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
    p[0] = 1;
    FOR(i,1,n)
        p[i] = (1LL * p[i-1] * base) % MOD;
    int tc; cin>>tc;
    while (tc--)
    {
        mark.clear(), have.clear();
        cin>>n>>s>>t;
        string x;
        FOR(i,1,n)
        {
            cin>>x;
            have.insert(get_hash(x));
        }
        if (s == t) 
        {
            cout<<"1\n";
            continue;
        }
        bfs();
    }
}
