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
    stack<int> st;
    int q; cin>>q;
    while (q--)
    {
        string type; cin>>type;
        if (type == "PUSH")
        {
            int val; cin>>val;
            st.push(val);
        }
        else
        if (type == "POP")
        {
            if (!st.empty()) st.pop();
        }
        else
        if (type == "PRINT")
        {
            if (!st.empty()) cout<<st.top()<<"\n";
            else cout<<"NONE\n";
        }
    }
}
