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
        int n; cin>>n;	
        vi a(n+1), rs(n+1);
        FOR(i,1,n) cin>>a[i];
        stack<int> st;
        FOD(i,n,1)
        {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            if (!st.empty()) rs[i] = st.top();
            else rs[i] = -1;
            st.push(i);
        }
        deb(rs)
        while (st.size()) st.pop();
        vi ans(n+1);
        FOD(i,n,1)
        {
            while (!st.empty() && a[st.top()] <= a[i]) st.pop();
            if (!st.empty()) 
            {
                if (rs[st.top()] == -1) ans[i] = -1;
                else ans[i] = a[rs[st.top()]];
                deb(st.top(), rs[st.top()]);
            }
            else ans[i] = -1;
            st.push(i);
        }
        FOR(i,1,n) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}
