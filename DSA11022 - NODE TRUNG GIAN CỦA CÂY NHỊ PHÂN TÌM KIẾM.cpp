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
struct Node{
    int val;
    Node *left, *right;
    Node (int _val)
    {
        val = _val;
        left = right = NULL;
    }
};
void addNode(Node* &cur, int val)
{
    if (cur == NULL)
    {
        cur = new Node(val);
        return;
    }
    if (cur->val > val)
        addNode(cur->left, val);
    else
        addNode(cur->right, val);
}
vi ans;
void find_leaf(Node* cur)
{
    if (cur->left == NULL && cur->right == NULL)
        ans.push_back(cur->val);
    if (cur->left != NULL)
        find_leaf(cur->left);
    if (cur->right != NULL)
        find_leaf(cur->right);
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
        int n; cin>>n;
        int tmp = n;
        Node* root = NULL;
        while (n--)
        {
            int x; cin>>x;
            addNode(root, x);
        }
        ans.clear();
        find_leaf(root);
        cout<<tmp - ans.size();
        cout<<"\n";
    }
}
