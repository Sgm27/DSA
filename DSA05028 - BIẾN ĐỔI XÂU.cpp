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
		string s,t;	cin>>s>>t;
		int n = s.length(), m = t.length();
		s = " " + s;
		t = " " + t;
		vector<vi> dp(n+1,vi(m+1,INF));
		FOR(i,0,n)
			dp[i][0] = i;
		FOR(i,0,m) 
			dp[0][i] = i;
		FOR(i,1,n)
			FOR(j,1,m)
			{
				if (s[i] == t[j]) 
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
			}
		cout<<dp[n][m]<<"\n";
	}
}
