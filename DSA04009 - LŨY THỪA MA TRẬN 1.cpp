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
#define maxn 15
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
                    (c.val[i][j]+=val[i][k]*b.val[k][j])%=MOD;
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
	while (tc--)
	{
		int n,k;
		cin>>n>>k;
		matrix ans(n);
		for (int i=0;i<n;i++)
			for(int j=0;j<n;j++) cin>>ans.val[i][j];
		ans = ans.Pow(k);
		for (int i=0;i<n;i++) 
		{
			for (int j=0;j<n;j++) cout<<ans.val[i][j]<<" ";
			cout<<"\n";
		}
	}
}
