#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define int long long
#define pii pair<int,int>
#define maxn 
int n;
vector<string> ans;
void chuyen(int n,char a,char b)
{
    cout<<a<<" -> "<<b<<"\n";
}
void HN(int n,char a,char b,char c)
{
    if (n==1) chuyen(1,a,c);
    else
    {
        HN(n-1,a,c,b);
        chuyen(n,a,c);
        HN(n-1,b,a,c);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    HN(n,'A','B','C');
}