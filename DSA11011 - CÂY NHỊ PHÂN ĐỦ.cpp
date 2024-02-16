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
bool check(Node *root)
{
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while (!q.empty())
    {
        auto [cur, d] = q.front();
        q.pop();
        int num_child = 0;
        if (cur->left)
        {
            q.push({cur->left, d+1});
            num_child++;
        }
        if (cur->right)
        {
            q.push({cur->right, d+1});
            num_child++;
        }
        if (num_child & 1) return false;
    }
    return true;
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
        cout<<check(root)<<"\n";
    }
}
