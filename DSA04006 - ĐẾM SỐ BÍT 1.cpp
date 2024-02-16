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
int num[100];
// num[i] number of bit appeare in value i
vi compress;

int find_pos(int val)
{
    return lower_bound(ALL(compress), val) - compress.begin();
}
void prepare(int n)
{
    compress.clear();
    FOR(i,0,99) num[i] = 0;
    int tmp = n,check2 = 0, check3 = 0;
    while (tmp)
    {
        compress.push_back(tmp);
        check2 |= (tmp == 2);
        check3 |= (tmp == 3);
        tmp /= 2;
    }
    sort(ALL(compress));
    if (check2) 
        num[find_pos(2)] = 3;
    else 
        num[find_pos(3)] = 3;
    for (int i=2;i<compress.size();i++)
        num[i] = num[i-1] * 2 + 1;
}
int get_bit(int n,int k) // get bit in position k of value n
{
    if (n == 2 || n == 3)
    {
        if (k == 1) return 1;
        if (k == 2)
        {
            if (n == 2) return 0;
            else return 1;
        }
        if (k == 3) return 1;
    }
    int pos = num[find_pos(n / 2)];
    if (k == pos + 1) return n % 2;
    if (k <= pos) return get_bit(n / 2, k);
    if (k > pos + 1) return get_bit(n / 2, k - pos - 1);
    assert(0 == 1);
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
        int n,l,r; cin>>n>>l>>r;	
        prepare(n);
        int ans = 0;
        FOR(i,l,r)
            ans += get_bit(n,i);
        cout<<ans<<"\n";
    }
}