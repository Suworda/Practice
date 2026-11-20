#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Node{
    int l, r, mi, mx, mi_id, mx_id;
    Node *left, *right;
};

struct Segt{
    Node* root = new Node;
    vector<int> a;
    int n;
    
    Segt(vector<int> &p, int _n){
        n = _n;
        a = p;
        a[0] = -2e18;
        a[n+1] = 2e18;
        build(1, n, root);
    } 
    
    void pull(Node *rt){
        auto L = rt->left;
        auto R = rt->right;
        
        if(L->mi < R->mi){
            rt->mi = L->mi;
            rt->mi_id = L->mi_id;
        }
        else{
            rt->mi = R->mi;
            rt->mi_id = R->mi_id;
        }
        
        if(L->mx > R->mx){
            rt->mx = L->mx;
            rt->mx_id = L->mx_id;
        }
        else{
            rt->mx = R->mx;
            rt->mx_id = R->mx_id;
        }
    }
    
    void build(int l, int r, Node *rt){
        rt->l = l;
        rt->r = r;
        if(l == r){
            rt->mi_id = l;
            rt->mx_id = l;
            rt->mi = a[l];
            rt->mx = a[l];
            return;
        }
        
        rt->left = new Node;
        rt->right = new Node;
        
        int m = (l+r)/2;
        build(l, m, rt->left);
        build(m+1, r, rt->right);
        pull(rt);
    }
    
    void upd(int p, int v, Node *rt){
        int l = rt->l;
        int r = rt->r;
        
        if(l == p && r == p){
            a[p] = v;
            rt->mi_id = p;
            rt->mx_id = p;
            rt->mi = v;
            rt->mx = v;
            return;
        }

        int m = (l+r)/2;
        if(p <= m) upd(p, v, rt->left);
        else upd(p, v, rt->right);
        pull(rt);
    }

    pair<int,int> query(int ql, int qr, Node *rt){
        int l = rt->l;
        int r = rt->r;

        if(qr < l || r < ql) return {n+1, 0};

        if(ql <= l && r <= qr) return {rt->mi_id, rt->mx_id};

        auto x = query(ql, qr, rt->left);
        auto y = query(ql, qr, rt->right);

        auto [mi_id1, mx_id1] = x;
        auto [mi_id2, mx_id2] = y;

        int rst1 = n+1, rst2 = 0;
        if(a[mi_id1] < a[mi_id2]){
            rst1 = mi_id1;
        }
        else{
            rst1 = mi_id2;
        }

        if(a[mx_id1] > a[mx_id2]){
            rst2 = mx_id1;
        }
        else{
            rst2 = mx_id2;
        }

        return {rst1, rst2};
    }

    void print(){
        for(int i=1; i<=n; i++) cout << a[i] << ' ';
        cout << '\n';
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    vector<int> p(n+5);
    for(int i=1; i<=n; i++) cin>>p[i];

    Segt segt(p, n);

    while(m--){
        int l, r;
        cin>>l>>r;
        auto [mi_id, mx_id] = segt.query(l, r, segt.root);

        int mi = segt.a[mi_id];
        int mx = segt.a[mx_id];

        segt.upd(mi_id, mx, segt.root);
        segt.upd(mx_id, mi, segt.root);
    }

    segt.print();
}


