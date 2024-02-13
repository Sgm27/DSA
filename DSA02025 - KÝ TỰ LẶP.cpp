#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
// #define int long long
#define vi vector<int>
#define pii pair<int,int>
#define maxn 
vector<string> s;
int cur_ans = 1e9;
inline int rep(const string &a,const string &b)
{
    int mark[26] = {};
    for (char c : a) 
        mark[c - 'A']++;
    int cnt = 0;
    for (char c : b) 
        if (mark[c - 'A']) cnt++;
    return cnt;
};
inline int calc()
{
    int ans = 0;
    FOR(i,1,s.size()-1)
    {
        ans += rep(s[i], s[i-1]);
        if (ans >= cur_ans) break;
    }
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    while (n--)
    {
        string cur; cin>>cur;
        s.push_back(cur);
    }
    sort(ALL(s));
    do
    {
        cur_ans = min(cur_ans, calc());
    }
    while (next_permutation(ALL(s)));
    cout<<cur_ans;
}
