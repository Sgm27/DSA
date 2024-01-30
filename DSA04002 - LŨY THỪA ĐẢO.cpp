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
int Pow(int a, int n)
{
	if (!n) return 1;
	if (n==1) return a;
	int tmp=Pow(a,n/2)%MOD;
	tmp=tmp*tmp%MOD;
	if (n%2) tmp=tmp*a%MOD;
	return tmp;
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
		int n; cin>>n;
		string s = to_string(n);
		reverse(ALL(s));
		int revn = stoll(s);
		cout<<Pow(n, revn)<<"\n";
	}
}
