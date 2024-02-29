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
int m1[6] = {3,0,2,4,1,5};
int m2[6] = {0,4,1,3,5,2};

string move1(string a)
{
    string ans;
    FOR(i,0,5)
        ans.push_back(a[m1[i]]);
    return ans;
}
string move2(string a)
{
    string ans;
    FOR(i,0,5)
        ans.push_back(a[m2[i]]);
    return ans;
}
inline void bfs(string start, string des)
{
    queue<string> q;
    unordered_map<string,int> mark;
    mark[start] = 1;
    q.push(start);
    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        if (cur == des) 
            return cout<<mark[cur] - 1, void();
        string nxt = move1(cur);
        if (!mark[nxt]) 
        {
            mark[nxt] = mark[cur] + 1;
            q.push(nxt);
        }
        nxt = move2(cur);
        if (!mark[nxt]) 
        {
            mark[nxt] = mark[cur] + 1;
            q.push(nxt);
        }
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        string start, des;
        FOR(i,1,6) 
        {
            char x; cin>>x;
            start.push_back(x);
        }
        FOR(i,1,6)
        {
            char x; cin>>x;
            des.push_back(x);
        }
        bfs(start, des);
        cout<<"\n";
    }
}
