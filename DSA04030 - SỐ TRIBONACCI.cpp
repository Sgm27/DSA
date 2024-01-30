#include<bits/stdc++.h>
#ifdef DS
    #include "debug.h"
#else 
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
const int MOD=1e15+7,INF=4e18;
#define maxn 5

int mod(int a,int b)
{
    int res=0;
    a%=MOD;
    while (b)
    {
        if (b%2) res=(res+a)%MOD;
        a=(a*2)%MOD;
        b/=2;
    }
    return res;
}
struct matrix
{
    int val[maxn][maxn];
    int sz;
    matrix (int n)
    {
        sz=n;
        FOR(i,0,n)
            FOR(j,0,n) val[i][j]=0;
    }
    matrix operator * (matrix b)
    {
        matrix c(sz);
        for (int i=0;i<sz;i++)
            for (int j=0;j<sz;j++)
                for (int k=0;k<sz;k++)
                    (c.val[i][j]+=mod(val[i][k],b.val[k][j]))%=MOD;
        return c;
    }
    matrix Pow(int k)
    {
        matrix c(sz);
        for (int i=0;i<sz;i++) c.val[i][i]=1;
        for (matrix i = (*this);k;i = i*i,k/=2)
            if (k & 1) c=c*i;
        return c;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    int f[] = {0,1,3,6};
    matrix ans(4);
    ans.val[0][0] = 1, ans.val[0][1] = 1, ans.val[0][2] = 1, ans.val[0][3] = 0;
    ans.val[1][0] = 1, ans.val[1][1] = 0, ans.val[1][2] = 0, ans.val[1][3] = 0;
    ans.val[2][0] = 0, ans.val[2][1] = 1, ans.val[2][2] = 0, ans.val[2][3] = 0;
    ans.val[3][0] = 1, ans.val[3][1] = 1, ans.val[3][2] = 1, ans.val[3][3] = 1;
    while (tc--)
    {
        int n; cin>>n;
        if (n <= 3)
        {
            cout<<f[n]<<"\n";
            continue;
        }
        matrix new_ans = ans.Pow(n-3);
        int res = new_ans.val[3][0] * 3 + new_ans.val[3][1] * 2 + new_ans.val[3][2] + new_ans.val[3][3] * 6;
        res %= MOD;
        cout<<res<<"\n";
    }
}
