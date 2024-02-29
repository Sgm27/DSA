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
        vi a(n+1), l(n+1), r(n+1);
        FOR(i,1,n) cin>>a[i];
        stack<int> st;
        FOR(i,1,n)
        {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            if (st.size()) l[i] = st.top();
            else l[i] = 0;
            st.push(i);
        }
        while (st.size()) st.pop();
        FOD(i,n,1)
        {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            if (st.size()) r[i] = st.top();
            else r[i] = n+1;
            st.push(i);
        }
        int ans = 0;
        FOR(i,1,n)
            ans = max(ans, (r[i] - l[i] - 1) * a[i]);
        cout<<ans<<"\n";
    }
}
