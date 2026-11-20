#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

mt19937 rng(time(NULL));

struct Treap{
    struct Node {
        Node *l=0, *r=0;
        int val, pri, mi, sz=1;

        Node(int _val): val(_val), pri(rng()), mi(_val) {}

        void up(){
            mi = val;
            sz = 1;
            for(auto i: {l, r}){
                if(i){
                    sz += i->sz;
                    mi = min(mi, i->mi);
                }
            }
            
        }
    };

    Node* root = nullptr;

    int size(Node* rt){
        return (rt ? rt->sz : 0);
    }
    
    Node* new_node(int x){
        return new Node(x);
    }

    pair<Node*, Node*> split_by_size(Node *rt, int k){
        if(!rt) return {nullptr, nullptr};

        if(size(rt->l)+1 <= k){
            auto [a,b] = split_by_size(rt->r, k - (size(rt->l)+1));

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
            
            rt->l = b;
            rt->up();

            return {a, rt};
        }
    }

    Node *merge(Node *a, Node *b){
        if(!a) return b;
        if(!b) return a;

        if(a->pri > b->pri){
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

    void insert(int p, int x){
        auto [a,b] = split_by_size(root, p-1);
        root = merge(merge(a, new_node(x)), b);
    }

    
    void insert_by_val(int x){
        auto [a,b] = split_by_val(root, x-1);
        root = merge(merge(a, new_node(x)), b);   
    }

    void erase(int p){
        auto [ab,c] = split_by_size(root, p);
        auto [a,b] = split_by_size(ab, p-1);

        root = merge(a, c);
        delete b;
    }

    void upd(int p, int x){
        auto [ab, c] = split_by_size(root, p);
        auto [a, b] = split_by_size(ab, p-1);

        b->val = x;
        b->up();

        root = merge(merge(a, b), c);
    }

    int query_min(int l, int r){
        auto [ab,c] = split_by_size(root, r);
        auto [a, b] = split_by_size(ab, l-1);
        
        int ans = b->mi;
        
        root = merge(merge(a, b), c);

        return ans;
    }
};

signed main(){
    Treap tr;

    tr.insert(1, 5);
    tr.insert(2, 3);
    tr.insert(3, 8);

    cout << tr.query_min(1, 3) << '\n'; // 3

    tr.upd(2, 10);
    cout << tr.query_min(1, 3) << '\n'; // 5

    tr.erase(1);
}