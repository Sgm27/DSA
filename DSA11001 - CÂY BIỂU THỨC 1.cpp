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
    char val;
    Node *left,*right;
    Node(char c)
    {
        val = c;
        left = right = NULL;
    }
};
vi ans;
void inorder(Node *cur)
{
    if (cur == NULL) return;
    inorder(cur->left);
    ans.push_back(cur->val);
    inorder(cur->right);
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
        Node *root;
        stack<Node*> st;
        string s; cin>>s;
        for (char c : s)
            if (!isalpha(c))
            {
                root = new Node(c);
                Node *fi = st.top(); st.pop();
                Node *se = st.top(); st.pop();
                root->left = se;
                root->right = fi;
                st.push(root);
            }
            else
            {
                root = new Node(c);
                st.push(root);
            }
        ans.clear();
        inorder(root);
        for (char x : ans) cout<<x;
        cout<<"\n";
    }
}
