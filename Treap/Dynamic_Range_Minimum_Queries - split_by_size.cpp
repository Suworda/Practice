#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

mt19937 mt(time(NULL));
struct Node{
    Node *l=0, *r=0;
    int  pri, val, mi, sz;

    Node(int _val): pri(mt()), val(_val), mi(_val), sz(1) {}

    void up(){
        mi = val;
        sz = 1;
        if(l){
            mi = min(mi, l->mi);
            sz += l->sz;
        }
        if(r){
            mi = min(mi, r->mi);
            sz += r->sz;
        }
    }
};

Node* merge(Node *a, Node *b){
    if(!a) return b;
    if(!b) return a;

    if(a->pri < b->pri){
        a->r = merge(a->r, b);
        a->up();
        return a;
    }
    else{
        b->l = merge(a, b->l);
        b->up();
        return b;
    }
}

int size(Node *rt){
    return (rt ? rt->sz : 0);
}

void split_by_size(Node *rt, int k, Node *&a, Node *&b){
    if(!rt){
        a = b = 0;
        return;
    }
    
    if(size(rt->l)+1 <= k){
        a = rt;
        split_by_size(rt->r, k-(size(rt->l)+1), a->r, b);
        a->up();
    }
    else{
        b = rt;
        split_by_size(rt->l, k, a, b->l);
        b->up();
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin>>n>>q;

    Node *root = nullptr;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        root = merge(root, new Node(x));
    }

    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int k, u;
            cin>>k>>u;

            Node *a, *b, *c;

            split_by_size(root, k-1, a, b);
            split_by_size(b, 1, b, c);

            b->mi = b->val = u;

            root = merge(merge(a, b), c);
        }
        else{
            int l, r;
            cin>>l>>r;

            Node *a, *b, *c;

            split_by_size(root, l-1, a, b);
            split_by_size(b, r-l+1, b, c);

            cout << b->mi << '\n';

            root = merge(merge(a, b), c);
        }
    }
}