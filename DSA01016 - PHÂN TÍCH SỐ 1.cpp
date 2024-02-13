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
int n,x[25];
vector<vi> ans;
void Try(int i,int cur = n)
{
    // deb(i,cur)
    FOD(j,min(cur,x[i-1]),1)
    {
        // deb(j)
        x[i] = j;
        if (cur - x[i] == 0)
        {
            vi tmp(x+1,x+1+i);
            ans.push_back(tmp);
        }
        else 
            Try(i+1,cur - x[i]);
    }
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
        ans.clear();
        cin>>n;	
        x[0] = n;
        Try(1);
        for (auto &it : ans)
        {
            cout<<"(";
            for (int i=0;i<it.size()-1;i++) cout<<it[i]<<" ";
            cout<<it.back()<<") ";
        }
        cout<<"\n";
    }
}
