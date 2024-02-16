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
void sprialOrder(Node *root)
{
    queue<pair<Node*,int>> q;
    q.push({root,0});
    vector<vi> level;
    vi cur;
    int prev_level = -1;
    while (!q.empty())
    {
        deb(cur)
        auto [p, d] = q.front();
        q.pop();
        if (d != prev_level) 
        {
            level.push_back(cur);
            cur.clear();
            cur.push_back(p->val);
            prev_level = d;
        }
        else 
            cur.push_back(p->val);
        if (p->left)
            q.push({p->left, d+1});
        if (p->right)
            q.push({p->right, d+1});
    }
    level.push_back(cur);
    FOR(i,0,level.size()-1)
    {
        if (i % 2) reverse(ALL(level[i]));
        for (int x : level[i])
            cout<<x<<" ";
    }
    cout<<"\n";
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
        Node *root = NULL;	
        bool has_root = false;
        int m; cin>>m;
        while (m--)
        {
            int par,child;
            char type;
            cin>>par>>child>>type;
            if (!has_root)
            {
                root = new Node(par);
                has_root = true;
            }
            addNode(root, par, child, type);
        }
        sprialOrder(root);
    }
}
