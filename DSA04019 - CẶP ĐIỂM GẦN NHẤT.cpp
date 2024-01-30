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
using ld = long double;
const int MOD=1e9+7,INF=4e18;
#define maxn 
int n;
struct Point{
	int x,y,idx;
	friend bool operator<(const Point a,const Point b)
	{
		if (a.x != b.x)
			return a.x < b.x;
		return a.y < b.y;
	}
};
vector<Point> points;

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
		points.clear();
		cin>>n;
		int best = INF;
		FOR(i,1,n)
		{
			int x,y;
			cin>>x>>y;
			points.push_back({x,y,i});
		}
		set<pii> candidates;
		sort(ALL(points));
		int l = 0;
		for (int i = 0;i < n;i++)
		{
			int d = ceil(sqrt(best));
			while (l < n && points[i].x - points[l].x >= d)
			{
				candidates.erase({points[l].y,points[l].x});
				l++;
			} 
			auto it1 = candidates.lower_bound({points[i].y-d, points[i].x});
			auto it2 = candidates.upper_bound({points[i].y+d, points[i].x});
			for (auto it = it1; it != it2; it++)
			{
				int dx = points[i].x - it->second;
				int dy = abs(points[i].y - it->first);
				best = min(best, dx * dx + dy * dy);
			}
			candidates.insert({points[i].y, points[i].x});
		}
		ld ans = sqrt(best);
		cout<<fixed<<setprecision(6)<<ans<<"\n";
	}
}
