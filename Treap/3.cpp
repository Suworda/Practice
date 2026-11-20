#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

mt19937 rng(time(NULL));

struct Treap{
    struct Node{
        Node *l, *r;
        int val, pri, sz, mi;

        Node(int _val): val(_val), mi(_val), pri(rng()){} 

        void up(){
            int sz = 1;
            int mi = val;

            for(auto i: {l,r}){
                if(i){
                    sz += i->sz;
                    mi = min(mi, i->mi);
                }
            }
        }
    };

    Node* root = nullptr;

    Node* new_node(int x){
        return new Node(x);
    }

    int size(Node *rt){
        return rt ? rt->sz : 0;
    }

    pair<Node*, Node*> split_by_size(Node *rt, int k){
        if(!rt) return {nullptr, nullptr};

        if(size(rt->l)+1 <= k){
            auto [a,b] = split_by_size(rt->r, k-(size(rt->l)+1));

            rt->r = a;
            rt->up();

            return {rt, b};

        }
        else{
            auto [a,b] = split_by_size(rt->l, k);

            rt->l = b;
            rt->up();

            return {a, rt};
        }
    }

    pair<Node*, Node*> split_by_val(Node *rt, int k){
        if(!rt) return {nullptr, nullptr};

        if(rt->val <= k){
            auto [a,b] = split_by_val(rt->r, k);

            rt->r = a;
            rt->up();

            return {rt, b};
        }
        else{
            auto [a,b] = split_by_val(rt->l, k);

            rt->r = b;
            rt->up();

            return {a, rt};
        }
    }

    Node* merge(Node *a, Node *b){
        if(!a) return b;
        if(!b) return a;

        if(a->pri > b->pri){
            a = merge(a->r, b);
            a->up();
            return a;
        }
        else{
            b = merge(a, b->l);
            b->up();
            return b;
        }
    }

    void insert(int p, int x){
        auto [a, b] = split_by_size(root, p-1);

        root = merge(merge(a, new_node(x)), b);
    }

    void erase(int p){
        auto [ab, c] = split_by_size(root, p);
        auto [a,b] = split_by_size(ab, p-1);

        delete b;

        root = merge(a, c);
    }

    int query_min(int l, int r){
        auto [ab, c] = split_by_size(root, r);
        auto [a,b] = split_by_size(ab, l-1);

        int ans = b->mi;

        root = merge(merge(a, b), c);
    }
};

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    

}