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
int find_depth(Node *root)
{
    int ans = -INF;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto [cur, d] = q.front();
        q.pop();
        if (cur->left != NULL)
            q.push({cur->left, d+1});
        if (cur->right != NULL)
            q.push({cur->right, d+1});
        ans = max(ans, d);
    }
    return ans;
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
        cout<<find_depth(root)<<"\n";
    }
}
