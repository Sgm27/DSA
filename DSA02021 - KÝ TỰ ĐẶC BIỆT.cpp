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
const int MOD=1e9+7,INF=4e18;
#define maxn 
char ans;
int cnt = 0;
void find(string s,int N)
{
	int n = s.length();
	if (N <= n)
	{
		ans = s[N-1];
		return;
	}
	while (n < N) n <<= 1LL;
	n >>= 1;
	int pos = N - n;
	pos--;
	if (pos == 0) pos = n;
	return find(s, pos);
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
		int n; cin>>n;
		find(s,n);
		cout<<ans<<"\n";	
	}
}
