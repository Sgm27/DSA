#include<iostream>
#include<climits>
#include<string.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
bool check[1001],ok[100][100];
vector<int> A[1001];
int n, m,p;
int res = 1;
int DFS(int u) {
	int res = 0;
	for (int x : A[u]) {
		if (!ok[u][x]) {
			ok[u][x] = ok[x][u] = true;
			res = max(res, DFS(x) + 1);
			ok[u][x] = ok[x][u] = false;
		}
	}
    return res;
}
int main() {
    // freopen("thu.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		res = 1;
		for (int i = 0; i < 1001; i++)A[i].clear();
		int n, m; cin >> n >> m;
		p = n;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			A[a].push_back(b);
			A[b].push_back(a);
		}
		for (int i = 0; i < p; i++) {
			memset(ok, false, sizeof(ok));
			res = max(res, DFS(i));
		}
		cout << res << endl;
	}
}