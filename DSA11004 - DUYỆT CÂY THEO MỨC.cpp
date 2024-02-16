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
struct Node{
    int val;
    Node *left, *right;
    Node (int _val)
    {
        val = _val;
        left = right = NULL;
    }
};
void addNode(Node* &cur, int par, int val, char type)
{
    if (cur == NULL) 
        return;
    if (cur->val == par)
    {
        if (type == 'L') 
            cur->left = new Node(val);
        else
            cur->right = new Node(val);
    }
    else
    {
        addNode(cur->left,par,val,type);
        addNode(cur->right,par,val,type);
    }
}
void levelOrder(Node *root)
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        cout<<cur->val<<" ";
        if (cur->left) 
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
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
        int m; cin>>m;
        Node *root = NULL;
        bool first = true;
        while (m--)
        {
            int par,child;
            char type; 
            cin>>par>>child>>type;
            if (first) 
            {
                root = new Node(par);
                first = false;
            }
            addNode(root, par, child, type);
        }
        levelOrder(root);
        cout<<"\n";
    }
}
