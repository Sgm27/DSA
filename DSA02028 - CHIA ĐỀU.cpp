#include<iostream>
using namespace std;
using ll = long long;
#define maxn 
int sum[20],x[20],res,n,k,a[20];
void update()
{
    int tmp=sum[x[1]];
    if (tmp!=sum[n]-sum[x[k]]) return;
    for (int i=2;i<=k;i++)
        if (sum[x[i]]-sum[x[i-1]]!=tmp) return;
    res++;
}
void Try(int i)
{
    for (int j=x[i-1]+1;j<n;j++)
    {
        x[i]=j;
        if (i==k) update();
        else Try(i+1);
    }
}
int main()
{
    #ifdef DS
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc = 1;
    while (tc--)
    {
        res=sum[0]=0;
        cin>>n>>k;
        for (int i=1;i<=n;i++) 
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        if (k>n) 
        {
            cout<<"0\n";
            continue;
        }
        if (k==1)
        {
            cout<<"1\n";
            continue;
        }
        k--;
        x[0]=0;
        Try(1);
        cout<<res<<"\n";
    }
}

