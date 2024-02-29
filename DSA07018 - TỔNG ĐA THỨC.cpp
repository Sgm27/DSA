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

void solve(string s1,string s2)
{
    map<int,int> cnt;
    stringstream ss1(s1);
    string token;
    while (ss1 >> token)
    {
        if (token == "+") continue;
        string tmp;
        while (token.back() != '^') 
        {
            tmp.push_back(token.back());
            token.pop_back();
        }
        reverse(ALL(tmp));
        string tmp1;
        reverse(ALL(token));
        while (token.back() != '*') 
        {
            tmp1.push_back(token.back());
            token.pop_back();
        }
        cnt[stoll(tmp)] += stoll(tmp1);
    }
    stringstream ss2(s2);
    while (ss2 >> token)
    {
        if (token == "+") continue;
        string tmp;
        while (token.back() != '^') 
        {
            tmp.push_back(token.back());
            token.pop_back();
        }
        reverse(ALL(tmp));
        string tmp1;
        reverse(ALL(token));
        while (token.back() != '*') 
        {
            tmp1.push_back(token.back());
            token.pop_back();
        }
        cnt[stoll(tmp)] += stoll(tmp1);
    }
    deb(cnt)
    vector<pii> ans(ALL(cnt));
    reverse(ALL(ans));
    for (int i=0;i<ans.size()-1;i++)
        cout<<ans[i].second<<"*x^"<<ans[i].first<<" + ";
    cout<<ans.back().second<<"*x^"<<ans.back().first<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    cin.ignore();
    while (tc--)
    {
        string s1,s2;	
        getline(cin, s1);
        getline(cin, s2);
        solve(s1, s2);
    }
}
