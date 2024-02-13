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
#define maxn 2
struct matrix
{
    int val[maxn][maxn] = {};
    friend matrix operator*(const matrix A,const matrix B)
    {
        matrix ans;
        FOR(i,0,1)
            FOR(j,0,1)
                FOR(k,0,1) 
                {
                    ans.val[i][j] += A.val[i][k] * B.val[k][j];
                    ans.val[i][j] %= MOD;
                }
        return ans;
    }
};
matrix unit;
matrix Pow(const matrix A,int n)
{
    if (n == 0) return unit;
    if (n == 1) return A;
    matrix tmp = Pow(A, n / 2);
    tmp = tmp * tmp;
    if (n & 1) 
        tmp = tmp * A;
    return tmp;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    unit.val[0][0] = 1, unit.val[0][1] = 0;
    unit.val[1][0] = 0, unit.val[1][1] = 1;
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;	
        matrix A;
        A.val[0][0] = 1, A.val[0][1] = 1;
        A.val[1][0] = 1, A.val[1][1] = 0;
        A = Pow(A, n);
        cout<<A.val[1][0]<<"\n";
    }
}
