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
    deque<int> dq;
    int tc; cin>>tc;
    while (tc--)
    {
        string type;
        cin>>type;
        if (type == "PUSHBACK")
        {
            int val; cin>>val;
            dq.push_back(val);
        }
        else 
        if (type == "PUSHFRONT")
        {
            int val; cin>>val;
            dq.push_front(val);
        } 
        else 
        if (type == "PRINTFRONT")
        {
            if (dq.size()) cout<<dq.front()<<"\n";
            else cout<<"NONE\n";
        }
        else
        if (type == "PRINTBACK")
        {
            if (dq.size()) cout<<dq.back()<<"\n";
            else cout<<"NONE\n";
        }
        else
        if (type == "POPFRONT")
        {
            if (dq.empty()) continue;
            dq.pop_front();
        }
        else
        {
            if (dq.empty()) continue;
            dq.pop_back();
        }
    }
}
