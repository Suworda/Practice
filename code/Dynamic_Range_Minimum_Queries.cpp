#include <bits/stdc++.h>
using namespace std;
#define lid id*2
#define rid id*2+1

int a[200005];
int seg[800005];

void pull(int id){
    seg[id] = min(seg[lid], seg[rid]);
}

void build(int l, int r, int id){
    if(l == r){
        seg[id] = a[l];
        return;
    }

    int m = (l+r)/2;
    build(l, m, lid);
    build(m+1, r, rid);
    pull(id);
}

void upd(int l, int r, int p, int x, int id){
    if(l == p && r == p){
        seg[id] = x;
        return;
    }
    if(p < l || r < p) return;

    int m = (l+r)/2;
    if(p <= m) upd(l, m, p, x, lid);
    else upd(m+1, r, p, x, rid);
    pull(id);
}

int query(int l, int r, int ql, int qr, int id){
    if(ql <= l && r <= qr) return seg[id];
    if(qr < l || r < ql) return 2e9;

    int m = (l+r)/2;
    return min(query(l, m, ql, qr, lid), query(m+1, r, ql, qr, rid));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];

    build(1,n,1);

    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int k,u;
            cin>>k>>u;
            upd(1,n,k,u,1);
        }else{
            int a,b;
            cin>>a>>b;
            cout<<query(1,n,a,b,1)<<'\n';
        }
    }
}