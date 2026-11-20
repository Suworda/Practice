#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define l_id 2*id
#define r_id 2*id+1

int n,q;
int a[200005], seg[800005];

void pull(int id){
    seg[id] = min(seg[l_id], seg[r_id]);
}

void build(int l, int r, int id){
    if(l == r){
        seg[id] = a[l];
        return;
    }

    int m = (l+r)/2;
    build(l, m, l_id); build(m+1, r, r_id);
    pull(id);

}

void upd(int l, int r, int k, int v, int id){
    if(l == k && r == k){
        a[k] = v;
        seg[id] = v;
        return;
    }

    int m = (l+r)/2;
    if(k <= m) upd(l, m, k, v, l_id);
    else upd(m+1, r, k, v, r_id);
    pull(id);
}

int query(int l, int r, int ql, int qr, int id){
    if(ql <= l && r <= qr){
        return seg[id];
    }
    if(r < ql || qr < l) return 2e9;

    int m = (l+r)/2;
    int rst1 = query(l, m, ql, qr, l_id);
    int rst2 = query(m+1, r, ql, qr, r_id);

    return min(rst1, rst2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];

    build(1, n, 1);

    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int k,u;
            cin>>k>>u;
            upd(1, n, k, u, 1);

        }else{
            int a,b;
            cin>>a>>b;
            cout << query(1, n, a, b, 1) << '\n';

        }
    }

}