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
    Node *left,*right;
    Node(int _val)
    {
        val = _val;
        left = right = NULL;
    }
};
int ans;
map<Node*,int> dp;
void addNode(Node* &cur, int par, int child, char type)
{
    if (cur == NULL)
        return;
    if (cur->val == par)
    {
        if (type == 'L')
            cur->left = new Node(child);
        else 
            cur->right = new Node(child);
        return;
    }
    addNode(cur->left, par, child, type);
    addNode(cur->right, par, child, type);
}
void dfs(Node* cur)
{
    if (cur->left != NULL)
        dfs(cur->left);
    if (cur->right != NULL)
        dfs(cur->right);
    if (cur->left == NULL && cur->right == NULL)
        dp[cur] = cur->val;
    else
    {
        dp[cur] = -INF;
        if (cur->left != NULL)
            dp[cur] = max(dp[cur], dp[cur->left] + cur->val);
        if (cur->right != NULL)
            dp[cur] = max(dp[cur], dp[cur->right] + cur->val);    
    }
    if (cur->left != NULL && cur->right != NULL)
        ans = max(ans, dp[cur->left] + dp[cur->right] + cur->val);
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
        ans = -INF;
        dp.clear();
        Node *root = NULL;	
        int m; cin>>m;
        while (m--)
        {
            int par,child;
            char type;
            cin>>par>>child>>type;
            if (root == NULL)
                root = new Node(par);
            addNode(root, par, child, type);
        }
        dfs(root);
        // for (auto it : dp)
        //     cout<<it.first->val<<" "<<it.second<<"\n";
        cout<<ans<<"\n";  
    }
}