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
// #define int long long
#define max_bfs 1<<13
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7;
#define maxn 
int f1[10] = {3,0,2,7,4,1,6,8,5,9}; 
int f2[10] = {0,4,1,3,8,5,2,7,9,6};
int b1[10] = {1,5,2,0,4,8,6,3,7,9};
int b2[10] = {0,2,6,3,1,5,9,7,4,8};
unordered_map<string,int> D1,D2;
string des = "1238004765";
string turn_forward1(string s)
{
    string ans = "";
    FOR(i,0,9)
        ans += s[f1[i]];
    return ans;
}
string turn_forward2(string s)
{
    string ans = "";
    FOR(i,0,9)
        ans += s[f2[i]];
    return ans;
}
string turn_back1(string s)
{
    string ans = "";
    FOR(i,0,9)
        ans += s[b1[i]];
    return ans;
}
string turn_back2(string s)
{
    string ans = "";
    FOR(i,0,9)
        ans += s[b2[i]];
    return ans;
}
void bfs_back(string s)
{
    queue<string> q;
    q.push(s);
    D1[s] = 1; 
    int cnt_bfs = 0;
    while (!q.empty())
    {
        if (cnt_bfs++ > max_bfs) return;
        string cur = q.front();
        q.pop();
        string pre1 = turn_back1(cur);
        if (!D1[pre1])
        {
            D1[pre1] = D1[cur] + 1;
            q.push(pre1);
        }
        string pre2 = turn_back2(cur);
        if (!D1[pre2])
        {
            D1[pre2] = D1[cur] + 1;
            q.push(pre2);
        }
    }
}
void bfs_forward(string s)
{
    if (D1[s]) 
        return cout<<D1[s] - 1<<"\n", void();
    queue<string> q;
    q.push(s);
    D2[s] = 1;
    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        string nxt1 = turn_forward1(cur);
        string nxt2 = turn_forward2(cur);
        if (D1[nxt1])
            return cout<<D2[cur] + D1[nxt1] - 1<<"\n", void();
        if (D1[nxt2])
            return cout<<D2[cur] + D1[nxt2] - 1<<"\n", void();
        if (!D2[nxt1])
        {
            D2[nxt1] = D2[cur] + 1;
            q.push(nxt1);
        }
        if (!D2[nxt2])
        {
            D2[nxt2] = D2[cur] + 1;
            q.push(nxt2);
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
    bfs_back(des);
    int tc; cin>>tc;
    while (tc--)
    {
        string s = "";
        FOR(i,0,9)
        {
            char c; cin>>c;
            s += c;
        }
        D2.clear();
        bfs_forward(s);
    }
}
