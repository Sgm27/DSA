#ifdef DS
#include "debug.h"
#else
#include <bits/stdc++.h>
#define deb(...)
#endif
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define ALL(x) x.begin(), x.end()
#define NALL(x) x.begin() + 1, x.end()
#define TIME "Time elapsed : " << (double)clock() / 1000 << " s"
#define int long long
#define vi vector<int>
#define pii pair<int, int>
const int MOD = 1e9 + 7, INF = 4e18;
#define maxn
int n, k, a[25];
bool mark[25], ans;
void Try(int i, int nset, int cur_sum, int need_sum)
{
    if (ans) return;
    if (i == n+1)
    {
        if (nset == k) 
        {
            ans = true;
            return;
        }
        return;
    }
    FOR(j, 1, n)
        if (!mark[j] && cur_sum + a[j] <= need_sum)
        {
            mark[j] = 1;
            if (cur_sum + a[j] == need_sum)
                Try(i + 1, nset + 1, 0, need_sum);
            else
                Try(i + 1, nset, cur_sum + a[j], need_sum);
            mark[j] = 0;
        }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("thu.inp", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n >> k;
        int sum = 0;
        ans = false;
        memset(mark, 0, sizeof mark);
        FOR(i, 1, n)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % k)
            cout << "0\n";
        else
        {
            int need = sum / k;
            deb(need)
            Try(1, 0, 0, need);
            cout << ans << "\n";
        }
    }
}
