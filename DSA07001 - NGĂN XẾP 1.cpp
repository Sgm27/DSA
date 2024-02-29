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
    string type; 
    while (cin >> type)
    {
        int val; 
        if (type == "push") 
        {
            cin>>val;        
            st.push(val);
        }
        else
        if (!st.empty())
        {
            if (type == "show") 
            {
                vi ans;
                stack<int> tmp = st;
                while (!tmp.empty())
                {
                    ans.push_back(tmp.top());
                    tmp.pop();
                }
                reverse(ALL(ans));
                for (int x : ans) cout<<x<<" ";
                cout<<"\n";
            }
            else st.pop();
        }
        else cout<<"empty\n";
    }
}
