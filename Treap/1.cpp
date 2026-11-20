#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

mt19937 mt(time(NULL));
struct Node{
    Node *l=0, *r=0;
    int key, pri;
    Node(int x): key(x), pri(mt()) {}
    Node(int x, int _pri): key(x), pri(_pri) {}
};

void print_treap(Node *rt, string sp){
    if(!rt){
        cout << "Null\n";
        return;
    }
    cout << rt->key << " (pri = " << rt->pri << ")\n";
    if(!rt->l && !rt->r) return;
    cout << sp << "L : "; print_treap(rt->l, sp+"  ");
    cout << sp << "R : "; print_treap(rt->r, sp+"  ");
}

Node* merge(Node *a, Node *b){
    if(!a) return b;
    if(!b) return a;

    if(a->pri < b->pri){
        a->r = merge(a->r, b);
        return a;
    }
    else{
        b->l = merge(a, b->l);
        return b;
    }
}

void split(Node *rt, int k, Node *&a, Node *&b){
    if(!rt){
        a = b = 0;
        return;
    }

    cout<<"split "<<rt->key<<"\n";
    print_treap(rt,""); cout << '\n';
    
    if(rt->key < k){
        a = rt;
        split(a->r, k, a->r, b);
        cout<<"after split "<<rt->key<<" a\n";
        print_treap(a,""); cout << '\n';
    }
    else{
        b = rt;
        split(b->l, k, a, b->l);
        cout<<"after split "<<rt->key<<" b\n";
        print_treap(b,""); cout << '\n';
    }
}

Node* insert(Node *rt, int k){
    Node *a, *b;
    split(rt, k, a, b);
    return merge(merge(a, new Node(k)), b);
}

Node* erase(Node *rt, int k){
    Node *a, *b, *c;
    split(rt, k, a, b);
    split(b, k+1, b, c);
    return merge(a, c);
}


signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    Node* root = new Node(8, 1);
    root->l = new Node(3, 3);
    root->r = new Node(10, 4);
    root->l->l = new Node(1, 10);
    root->l->r = new Node(4, 7);
    root->l->r->r = new Node(7, 8);

    // Node *a, *b;
    // split(root, 5, a, b);
    // cout << "a : \n";
    // print_treap(a, "");
    // cout << '\n';
    // cout << "b : \n";
    // print_treap(b,"");
    // cout << '\n';
    
    cout << '\n';
    print_treap(root,"");
    cout << '\n';

    root = erase(root, 8);
    cout << "after erase\n";
    print_treap(root, "");
    cout << '\n';
    cout << "return 0";
}


