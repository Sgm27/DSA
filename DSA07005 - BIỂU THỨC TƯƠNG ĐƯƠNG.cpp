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
        string s; cin>>s;	
        // assert(*s.begin() != '(');
        int fl = 0;
        string ans;
        int last_sign = 0; // number of bracket start with minus
        FOR(i,0,s.length()-1)
        {
            if (s[i] != '(' && s[i] != ')') 
            {
                if (isalpha(s[i])) 
                {
                    ans.push_back(s[i]);
                    continue;
                }
                if (fl)
                {
                    if (s[i] == '-') ans.push_back('+');
                    if (s[i] == '+') ans.push_back('-');
                }
                else 
                    ans.push_back(s[i]);
            }
            if (s[i] == '(' && s[i-1] == '-')
            {
                fl ^= 1;
                last_sign++;
            } 
            if (s[i] == ')' && last_sign)
            {
                fl ^= 1;
                last_sign--;
            }
        }
        cout<<ans<<"\n";
    }
}
