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
#define maxn 103
int dp[10][maxn];
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int tc; cin>>tc;
	FOR(i,0,9)
		dp[i][1] = 1;
	FOR(i, 2, maxn-3)
	{
		FOR(cur_d, 0, 9)
			FOR(pre_d, 0, cur_d)
				(dp[cur_d][i] += dp[pre_d][i-1]) %= MOD;
	}
	while (tc--)
	{
		int n; cin>>n;
		int ans = 0;
		FOR(i,0,9)
			ans += dp[i][n];
		ans %= MOD;
		cout<<ans<<"\n";
	}
}
