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
#define maxn 1000006
struct Node{
    int val;
    Node *left, *right;
    Node(int _val)
    {
        val = _val;
        left = right = NULL;
    }
};
int n,a[maxn];
Node* build(int l,int r)
{
    if (l > r) 
        return NULL;
    int mid = l+r >> 1;
    Node *root = new Node(a[mid]);
    if (l == r) 
        return root;
    root->left = build(l,mid-1);
    root->right = build(mid+1,r);
    return root;
}
int count_leaf(Node* cur)
{
    if (cur == NULL)
        return 0;
    if (cur->left == NULL && cur->right == NULL)
        return 1;
    return count_leaf(cur->left) + count_leaf(cur->right);
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
        cin>>n;
        FOR(i,1,n) cin>>a[i];
        sort(a+1, a+1+n);
        Node *root = build(1,n);
        cout<<count_leaf(root)<<"\n";
    }
}
