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
#define maxn 1003
int n,pre[maxn];
struct Node{
    int val;
    Node *left,*right;
    Node (int _val)
    {
        val = _val;
        left = right = NULL;
    }
};
int pre_idx; // current index in preorder
Node* build(int l,int r)
{
    if (l > r || pre_idx > n) 
        return NULL;
    Node *root = new Node(pre[l]);
    if (l == r) 
        return root;
    int pos;
    FOR(i,l,r)
        if (pre[i] > pre[l]) 
        {
            pos = i;
            break;
        }
    root->left = build(l+1,pos-1);
    root->right = build(pos,r);
    return root;
}
void postOrder(Node *cur)
{
    if (cur == NULL)
        return;
    postOrder(cur->left);
    postOrder(cur->right);
    cout<<cur->val<<" ";
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
        FOR(i,1,n) cin>>pre[i];
        pre_idx = 1;
        Node *root = build(1,n);
        postOrder(root);
        cout<<"\n";
    }
}