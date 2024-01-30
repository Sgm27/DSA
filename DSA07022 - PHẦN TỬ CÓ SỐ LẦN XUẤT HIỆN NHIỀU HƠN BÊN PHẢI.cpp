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
int mark[1000006];
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
        vi a(n+1);
        FOR(i,1,n)
        {
            cin>>a[i];
            mark[a[i]]++;
        }
        vi ans(n+1);
        stack<int> st;
        FOD(i,n,1)
        {
            if (st.empty())
            {
                ans[i] = -1;
                st.push(a[i]);
            }
            else
            {
                while (!st.empty() && mark[a[i]] >= mark[st.top()]) st.pop();
                if (st.empty()) ans[i] = -1;
                else ans[i] = st.top();
                st.push(a[i]);
            }
        }
        FOR(i,1,n)
            mark[a[i]] = 0;
        FOR(i,1,n) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}
