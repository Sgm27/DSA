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
	auto check = [](vi a) -> bool
	{
		FOR(i,1,a.size()-1)
			if (abs(a[i] - a[i-1]) == 1) return false;
		return true;
	};
	int tc; cin>>tc;
	while (tc--)
	{
		int n; cin>>n;	
		vi a;
		FOR(i,1,n) a.push_back(i);
		do {
			if (check(a)) 
			{
				for (int x : a) cout<<x;
				cout<<"\n";
			}
		}
		while (next_permutation(ALL(a)));
	}
}
