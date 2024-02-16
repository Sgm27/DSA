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
#define bit(i,n) (n >> i & 1)
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 205
string s;
vector<pii> match;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    int N = 0; // number of open bracket
    stack<int> st;
    FOR(i,0,s.length()-1)
    {
        if (s[i] != '(' && s[i] != ')') continue;
        if (s[i] == '(') 
        {
            N++;
            st.push(i);
        }
        else 
        {
            match.push_back({st.top(), i});
            st.pop();
        }
    }
    assert(N == match.size());
    vector<string> ans;
    // gen expression
    for (int mask = 1; mask < (1 << N); mask++)
    {
        vi mark(s.length(), 0);
        for (int i=0;i<N;i++)
            if (bit(i,mask)) 
            {
                mark[match[i].first] = 1;
                mark[match[i].second] = 1;
            }
        string cur;
        FOR(i,0,s.length())
            if (!mark[i]) cur.push_back(s[i]);
        ans.push_back(cur);
    }
    sort(ALL(ans));
    ans.resize(unique(ALL(ans)) - ans.begin());
    for (auto it : ans) cout<<it<<"\n";
}
