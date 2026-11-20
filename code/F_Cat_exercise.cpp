#include <bits/stdc++.h>
using namespace std;

int n;
int p[200005];

struct Node{
    int l,r,val,idx;
    Node *left, *right;
};
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

void build(int l, int r, Node *rt){
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
    build(l, m, rt->left); build(m+1, r, rt->right);
    pull(rt);
}

int query(int l, int r, Node *rt){
    if(rt->r < l || r < rt->l){
        return -1;
    }
    if(l <= rt->l && rt->r <= r){
        return rt->idx;
    }

    int m = (l+r)/2;
    int rst_l = query(l, r, rt->left);
    int rst_r = query(l, r, rt->right);

    if(rst_l == -1 || (rst_r != -1 && p[rst_l] < p[rst_r])){
        return rst_r;
    }else{
        return rst_l;
    }
}


long long f(int l, int r, int cur_idx){

    if(l == r) return 0;

    int rst_l = query(l, cur_idx-1, root);
    int rst_r = query(cur_idx+1, r, root);
    if(cur_idx+1 > r){
        return f(l, cur_idx-1, rst_l) + (cur_idx - rst_l);

    }
    if(cur_idx-1 < l){
        return f(cur_idx+1, r, rst_r) + (rst_r - cur_idx);

    }

    return max(f(l, cur_idx-1, rst_l) + (cur_idx - rst_l),  f(cur_idx+1, r, rst_r) + (rst_r - cur_idx));
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