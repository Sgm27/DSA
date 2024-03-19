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
    int heSo, mu;
    Node* next;
    Node (int HeSo,int Mu)
    {
        heSo = HeSo;
        mu = Mu;
        next = NULL;
    }
};
void addNode(Node* &cur,int hs,int mu)
{
    if (cur == NULL)
    {
        cur = new Node(hs, mu);
        return;
    }
    Node* tmp = cur;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new Node(hs, mu);
}
int maxMu = -INF;
void makeNode(string s, Node* &head)
{
    stringstream ss(s);
    string token;
    while (ss >> token)
    {
        if (token == "+") continue;
        string tmp;
        while (token.back() != '^') 
        {
            tmp.push_back(token.back());
            token.pop_back();
        }
        reverse(ALL(tmp));
        string tmp1;
        reverse(ALL(token));
        while (token.back() != '*') 
        {
            tmp1.push_back(token.back());
            token.pop_back();
        }
        maxMu = max(maxMu, stoll(tmp));
        addNode(head, stoll(tmp1), stoll(tmp));
    }
}
int getHS(Node* cur, int soMu)
{
    while (cur != NULL)
    {
        if (cur->mu == soMu)
            return cur->heSo;
        cur = cur->next;
    }
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
    cin.ignore();
    while (tc--)
    {
        Node *h1 = NULL, *h2 = NULL;
        string s;
        getline(cin, s);
        makeNode(s, h1);
        getline(cin, s);
        makeNode(s, h2);
        Node *head = NULL;
        FOD(i,maxMu,0)
            addNode(head, getHS(h1,i) + getHS(h2,i), i);
        while (head != NULL)
        {
            if (head -> heSo)
                cout<<head->heSo<<"*x^"<<head->mu;
            head = head->next;
            if (head != NULL && head->heSo)
                cout<<" + ";
        }
        cout<<"\n";
    }
}
