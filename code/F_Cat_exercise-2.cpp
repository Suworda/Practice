#include <bits/stdc++.h>
using namespace std;

struct Node{
    int l,r,idx,val;
    Node *left, *right;
};

int n;
int p[200005];
Node *root = new Node;

void pull(Node *rt){
    if(rt->left->val > rt->right->val){
        rt->idx = rt->left->idx;
        rt->val = rt->left->val;
    }else{
        rt->idx = rt->right->idx;
        rt->val = rt->right->val;
    }
}

void build(int l, int r, Node* rt){
    rt->l = l;
    rt->r = r;
    if(l == r){
        rt->idx = l;
        rt->val = p[l];
        return;
    }
    
    rt->left = new Node;
    rt->right = new Node;

    int m = (l+r)/2;
    build(l, m, rt->left);
    build(m+1, r, rt->right);
    pull(rt);

}
long long query(int l, int r, Node *rt){
    if(rt->r < l || r < rt->l) return -1;
    if(l <= rt->l && rt->r <= r) return rt->idx;

    int rst_l = query(l, r, rt->left);
    int rst_r = query(l, r, rt->right);

    if(rst_r == -1 || p[rst_l] > p[rst_r]) return rst_l;

    else return rst_r;
}


long long f(int l, int r, int idx){
    if(l == r) return 0;

    int rst_l = query(l, idx-1, root);
    int rst_r = query(idx+1, r, root);

    if(idx-1 < l) return f(idx+1, r, rst_r) + (rst_r-idx);
    if(idx+1 > r) return f(l,idx-1,rst_l) + (idx-rst_l);

    return max(f(l,idx-1,rst_l) + (idx-rst_l) , f(idx+1, r, rst_r) + (rst_r-idx));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }

    build(1,n,root);

    int rst = query(1,n,root);
    cout<<f(1,n,rst);

}