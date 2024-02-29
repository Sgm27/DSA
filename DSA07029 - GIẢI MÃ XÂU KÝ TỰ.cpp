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

void solve(string s)
{
    string new_s; // modify to correct form : num[] because have test ""[]
    FOR(i,0,s.length() - 1)
    {
        if (s[i] != '[') new_s += s[i];
        else
        {
            if (!new_s.size() || !isdigit(new_s.back())) new_s += '1';
            new_s += s[i];
        }
    }
    s = new_s;
    deb(s)
    stack<string> res;
    stack<int> num;
    int i = 0;
    while (i < s.size())
    {
        // deb(res, num)
        if (isdigit(s[i]))
        {
            string tmp = "";
            while (i < s.size() && isdigit(s[i])) tmp += s[i++];
            i--;
            num.push(stoll(tmp));
        }
        else
        {
            if (s[i] != ']') res.push(string(1, s[i]));
            else
            {
                vector<string> tmp;
                while (res.top() != "[") 
                {
                    tmp.push_back(res.top());
                    res.pop();
                }
                res.pop();
                reverse(ALL(tmp));
                string x;
                for (auto it : tmp) x += it;
                int N = num.top();
                num.pop();
                string new_str;
                FOR(j,1,N) new_str += x;
                res.push(new_str);
            }
        }
        i++;
    }
    vector<string> ans;
    while (res.size())
    {
        ans.push_back(res.top());
        res.pop();
    }
    reverse(ALL(ans));
    for (auto it : ans) cout<<it;
    cout<<"\n";
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
        solve(s);	
    }
}
