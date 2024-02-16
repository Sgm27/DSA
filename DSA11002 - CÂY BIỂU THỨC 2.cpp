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
vector<string> a;
struct Node{
    string val;
    Node *left, *right;
    Node(string _val)
    {
        val = _val;
        left = right = NULL;
    }
};
Node *build(int idx)
{
    if (idx < a.size())
    {
        Node *root = new Node(a[idx]);
        root -> left = build(idx * 2 + 1);
        root -> right = build(idx * 2 + 2);
        return root;
    }
    return NULL;
}
int get(Node *root)
{
    if (isdigit(root->val[0])) 
        return stoll(root->val);
    if (root->val == "-") 
        return get(root->left) - get(root->right);
    if (root->val == "+") 
        return get(root->left) + get(root->right);
    if (root->val == "*") 
        return get(root->left) * get(root->right);
    if (root->val == "/") 
        return get(root->left) / get(root->right);
    return 0;
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
        cin.ignore();
        a.clear();
        string s; 
        getline(cin, s);
        stringstream ss(s);
        string token;
        while (ss >> token) 
            a.push_back(token);
        Node *root = build(0);
        cout<<get(root)<<"\n";
    }
}
