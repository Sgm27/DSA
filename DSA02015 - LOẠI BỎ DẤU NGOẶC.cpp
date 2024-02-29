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
bool check(const string &s)
{
    if (s.size() < 2) return false;
    int cnt = 0;
    for (char c : s)
    {
        if (c == '(') cnt++;
        if (c == ')') cnt--;
        if (cnt < 0) 
            return false;
    }
    return cnt == 0;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        string s; cin>>s;
        queue<string> q;
        q.push(s);
        vector<string> ans;
        unordered_map<string,int> have;
        bool stop = 0;
        while (!q.empty())
        {
            string cur = q.front();
            q.pop();
            if (check(cur))
            {
                ans.push_back(cur);
                stop = 1;
            }
            if (stop) continue;
            for (int i=0;i<cur.size();i++)
            {
                if (cur[i] != '(' && cur[i] != ')') continue;
                string tmp = cur;
                tmp.erase(tmp.begin()+i);
                if (have[tmp]) continue;
                have[tmp] = 1;
                q.push(tmp);
            }
        }
        sort(ALL(ans));
        if (ans.size())
            for (const string &s : ans) cout<<s<<" ";
        else 
            cout<<"-1";
        cout<<"\n";
    }
}