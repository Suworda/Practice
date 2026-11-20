#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

mt19937 mt(time(NULL));
struct Node{
    Node *l=0, *r=0;
    int  pri, val, sum, sz, add_tag=0, set_tag=0;

    Node(int _val): pri(mt()), val(_val), sum(_val), sz(1) {}

    void up(){
        sum = val;
        sz = 1;
        if(l){
            sz += l->sz;
            sum += l->sum;
        }
        if(r){
            sz += r->sz;
            sum += r->sum;
        }
    }

    void down(){
        for(auto i: {l,r}){
            if(i){
                if(set_tag){
                    // cerr << set_tag << '\n';
                    i->set_tag = set_tag;
                    i->add_tag = 0;
                    i->val = set_tag;
                    i->sum = i->sz*set_tag;
                }

                i->add_tag += add_tag;
                i->val += add_tag;
                i->sum += i->sz*add_tag;
            }
        }
        add_tag = 0;
        set_tag = 0;
    }

    void add(int x){
        add_tag += x;
        val += x;
        sum += sz*x;
    }

    void set(int x){
        set_tag = x;
        add_tag = 0;
        val = x;
        sum = sz*x;
    }
};

Node* merge(Node *a, Node *b){
    if(!a) return b;
    if(!b) return a;

    a->down();
    b->down();

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

    rt->down();
    
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
        
        Node *a, *b, *c;

        if(ty == 1){ //add
            int l, r, x;
            cin >> l >> r >> x;

            split_by_size(root, r, b, c);
            split_by_size(b, l-1, a, b);

            b->add(x);

            root = merge(merge(a, b), c);

        }
        else if(ty == 2){ //set
            int l, r, x;
            cin >> l >> r >> x;
            
            split_by_size(root, r, b, c);
            split_by_size(b, l-1, a, b);

            b->set(x);

            root = merge(merge(a, b), c);
            
        }
        else{ //query
            int l, r;
            cin >> l >> r;

            split_by_size(root, r, b, c);
            split_by_size(b, l-1, a, b);

            cout << b->sum << '\n';

            root = merge(merge(a, b), c);
        }
    }
}