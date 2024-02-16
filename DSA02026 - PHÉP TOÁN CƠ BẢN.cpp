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
string res;
bool check(string s)
{
    // deb(s)
    string t = s;
    stringstream ss(s);
    vector<string> tmp;
    string token;
    while (ss >> token) tmp.push_back(token);
    int a = stoll(tmp.front());
    int b = stoll(tmp[2]);
    int c = stoll(tmp.back());
    if (a < 10 || b < 10 || c < 10) return 0;
    if (tmp[1] == "+" && a+b == c) 
    {
        res = t;
        return 1;
    }
    if (tmp[1] == "-" && a-b == c) 
    {
        res = t;
        return 1;
    }
    if (tmp[1] == "*" && a*b == c) 
    {
        res = t;
        return 1;
    }
    if (tmp[1] == "/" && b && (a%b == 0) && a/b == c) 
    {
        res = t;
        return 1;
    }
    return 0;
}
string S;
bool ans = false;
void Try(int i, string cur = "")
{
    if (ans) return;
    if (i == S.length()) 
    {
        if (check(cur)) ans = true;
        return;
    }
    if (S[i] != '?')
        Try(i+1, cur + S[i]);
    else
    {
        if (i != 3)
            FOR(j,0,9) Try(i+1, cur + string(1,j + '0'));
        else
        {
            Try(i+1, cur + "+");
            Try(i+1, cur + "-");
            Try(i+1, cur + "*");
            Try(i+1, cur + "/");
        }
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    // ios_base::sync_with_stdio(0);
    // cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        scanf("\n");
        ans = false;
        getline(cin, S);
        deb(S);
        Try(0);
        if (ans) cout<<res<<"\n";
        else cout<<"WRONG PROBLEM!\n";
    }
}
