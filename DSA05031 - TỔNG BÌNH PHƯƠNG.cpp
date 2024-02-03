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
#define maxn 10000
int dp[maxn+5];
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	FOR(i,1,100)
		FOR(j,i*i,maxn)
			dp[j] = min(dp[j], dp[j - i*i] + 1);
	int tc; cin>>tc;
	while (tc--)
	{
		int n; cin>>n;	
		cout<<dp[n]<<"\n";
	}
}
