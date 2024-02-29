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
#define maxn 1005
int fact[maxn],inv_fact[maxn],inv2;
int Pow(int a, int n)
{
    if (!n) return 1;
    if (n==1) return a;
    int tmp=Pow(a,n/2)%MOD;
    tmp=tmp*tmp%MOD;
    if (n%2) tmp=tmp*a%MOD;
    return tmp;
}
void init()
{
    inv2 = Pow(2, MOD-2);
    fact[0] = 1;
    FOR(i,1,maxn-3)
    {
        fact[i] = (fact[i-1] * i) %MOD;
        inv_fact[i] = Pow(fact[i], MOD - 2);
    }
}
int C(int n,int k)
{
    if (k == 0)
        return 1;
    int ans = (fact[n] * inv_fact[n-k]) %MOD;
    return (ans * inv_fact[k]) %MOD;
}
int get_ans(int n,int k)
{
    if (!k) return n %MOD;
    n %= MOD;
    vi ans;
    FOR(i,1,k)
    {
        if (i == 1)
            ans.push_back((((n * (n+1)) %MOD) * inv2) %MOD);
        else
        {
            int kk = i+1;
            int res = (Pow((n+1) %MOD, kk) - 1 - n + MOD*MOD) %MOD;
            FOR(j,0,ans.size()-1)
            {
                // assert(kk <= 1000 && kk - j - 1 <= 1000 && kk - j - 1 >= 0);
                res -= (ans[j] * C(kk, kk - j - 1)) %MOD;
                res = (res + MOD * MOD) %MOD;
            } 
            int tmp = Pow(kk, MOD-2);
            res = (res * tmp) %MOD;
            ans.push_back(res);
        }
    }
    return ans.back();
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int n,k; cin>>n>>k;
        cout<<get_ans(n,k)<<"\n";
    }
}