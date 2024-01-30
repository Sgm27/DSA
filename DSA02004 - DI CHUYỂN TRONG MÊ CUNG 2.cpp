#include<iostream>
using namespace std;
using ll = long long;
#define maxn 
bool flag,d[15][15];
int n,a[15][15];
string s;
void Try(int i,int j)
{
    if (i==n && j==n)
    {
        flag=true;
        cout<<s<<" ";
        return;
    }
    if (i<n && a[i+1][j] && d[i+1][j]) 
    {
        d[i+1][j]=false;
        s+="D";
        Try(i+1,j);
        s.pop_back();
        d[i+1][j]=true;
    }
    if (j>1 && a[i][j-1] && d[i][j-1]) 
    {
        d[i][j-1]=false;
        s+="L";
        Try(i,j-1);
        s.pop_back();
        d[i][j-1]=true;
    }
    if (j<n && a[i][j+1] && d[i][j+1]) 
    {
        d[i][j+1]=false;
        s+="R";
        Try(i,j+1);
        s.pop_back();
        d[i][j+1]=true;
    }
    if (i>1 && a[i-1][j] && d[i-1][j]) 
    {
        d[i-1][j]=false;
        s+="U";
        Try(i-1,j);
        s.pop_back();
        d[i-1][j]=true;
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        s="";
        flag=false;
        cin>>n;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) 
            {
                cin>>a[i][j];
                d[i][j]=true;
            }
        if (!a[1][1] || !a[n][n]) 
        {
            cout<<"-1\n";
            continue;
        }
        d[1][1]=false;
        Try(1,1);
        if (!flag) cout<<"-1\n";
        else cout<<"\n";
    }
}