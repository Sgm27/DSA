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
    int n; cin>>n;
    string s; cin>>s;
    int cntT = 0, cntD = 0, cntX = 0;
    s = " " + s;
    FOR(i,1,n)
        if (s[i] == 'T') cntT++;
        else 
        if (s[i] == 'D') cntD++;
        else cntX++;
    int step = 0;
    FOR(i,1,n)
    {
        if (cntX && s[i] == 'X')
        {
            cntX--;
            continue;
        }
        if (cntX == 0 && cntT && s[i] == 'T')
        {
            cntT--;
            continue;
        }
        if (cntX == 0 && cntT == 0 && cntD && s[i] == 'D')
        {
            cntD--;
            continue;
        }
        if (s[i] != 'X' && cntX)
        {
            int pos;
            if (s[i] == 'T')
            {
                FOR(j,i+cntX,n)
                    if (s[j] == 'X')
                    {
                        pos = j;
                        break;
                    }
            }
            else
            {
                FOD(j,n,i+1)
                    if (s[j] == 'X')
                    {
                        pos = j;
                        break;
                    }
            }
            swap(s[i], s[pos]);
            step++;
            cntX--;
        }
        else 
        if (s[i] != 'T' && cntT)
        {
            int pos;
            FOD(j,n,i+1)
                if (s[j] == 'T')
                {
                    pos = j;
                    break;
                }
            swap(s[i], s[pos]);
            step++;
            cntT--;
        }
        else
        if (s[i] != 'D' && cntD)
        {
            int pos;
            FOD(j,n,i+1)
                if (s[j] == 'D')
                {
                    pos = j;
                    break;
                }
            swap(s[i], s[pos]);
            step++;
            cntD--;
        }        
        deb(s)
    }
    cout<<step;
}
