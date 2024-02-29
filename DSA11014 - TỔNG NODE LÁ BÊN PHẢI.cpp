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
int sum_right_child(Node* cur)
{
    if (cur == NULL)
        return 0;
    int res = 0;
    if (cur->right != NULL && cur->right->left == NULL && cur->right->right == NULL)
        res += cur->right->val;
    res += sum_right_child(cur->left) + sum_right_child(cur->right);
    return res;
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
        map<int, Node*> mark;
        int m; cin>>m;
        while (m--)
        {
            int par,child;
            char type;
            cin>>par>>child>>type;
            if (root == NULL)
            {
                root = new Node(par);
                mark[par] = root;
            }
            Node* cur;
            if (type == 'L')
            {
                mark[par]->left = new Node(child);
                mark[child] = mark[par]->left;
            }
            if (type == 'R')
            {
                mark[par]->right = new Node(child);
                mark[child] = mark[par]->right;
            }
        }
        cout<<sum_right_child(root)<<"\n";
    }
}