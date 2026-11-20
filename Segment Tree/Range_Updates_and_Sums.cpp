#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Segt{
    
    struct Node{
        int l, r, len=0, sum=0, add_tag=0, set_tag=0;

        void apply_set_tag(int x){
            set_tag = x;
            add_tag = 0;

            sum = x*len;
        }

        void apply_add_tag(int x){
            add_tag += x;
            sum += x*len;
        }

    };

    int n;
    vector<int> a;
    vector<Node> seg; 

    Segt(const vector<int> &v): n(v.size()-1), seg(4*n+1), a(v){
        build(1, n, 1);
        // cout << n << ' ' << seg.size() << ' ' << a.size() << '\n';
    }

    inline int lc(int id){
        return id*2;
    }

    inline int rc(int id){
        return id*2+1;
    }

    void pull(int id){
        seg[id].sum = seg[lc(id)].sum + seg[rc(id)].sum;
    }

    void push(int id){
        if(seg[id].len <= 1) return;

        int set_tag = seg[id].set_tag;
        int add_tag = seg[id].add_tag;

        if(set_tag){
            seg[lc(id)].apply_set_tag(set_tag);
            seg[rc(id)].apply_set_tag(set_tag);
        }
        seg[lc(id)].apply_add_tag(add_tag);
        seg[rc(id)].apply_add_tag(add_tag);

        seg[id].set_tag = seg[id].add_tag = 0;
    }

    void build(int l, int r, int id){
        seg[id].l = l;
        seg[id].r = r;
        seg[id].len = r - l + 1;

        if(l == r){
            seg[id].sum = a[l];
            return;
        }

        int m = (l+r)/2;
        build(l, m, lc(id));
        build(m+1, r, rc(id));
        
        pull(id);
    }

    void add(int l, int r, int ql, int qr, int v, int id){
        if(qr < l || r < ql) return;

        if(ql <= l && r <= qr){
            seg[id].apply_add_tag(v);
            push(id);
            return;
        }
        
        push(id);

        int m = (l+r)/2;
        add(l, m, ql, qr, v, lc(id));
        add(m+1, r, ql, qr, v, rc(id)); 
        pull(id);
    }

    void set(int l, int r, int ql, int qr, int v, int id){
        if(qr < l || r < ql) return;

        if(ql <= l && r <= qr){
            seg[id].apply_set_tag(v);
            push(id);
            return;
        }
        
        push(id);

        int m = (l+r)/2;
        set(l, m, ql, qr, v, lc(id));
        set(m+1, r, ql, qr, v, rc(id));
        pull(id);
    }

    int query(int l, int r, int ql, int qr, int id){
        if(qr < l || r < ql) return 0;
        
        if(ql <= l && r <= qr) return seg[id].sum;

        push(id);

        int m = (l+r)/2;
        int rst1 = query(l, m, ql, qr, lc(id));
        int rst2 = query(m+1, r, ql, qr, rc(id));
        return rst1 + rst2;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    Segt segt(a);

    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int l, r, x;
            cin>>l>>r>>x;
            segt.add(1, n, l, r, x, 1);
            
        }
        else if(ty == 2){
            int l, r, x;
            cin>>l>>r>>x;
            segt.set(1, n, l, r, x, 1);

        }
        else{ //ty == 3
            int l, r;
            cin>>l>>r;

            cout << segt.query(1, n, l, r, 1) << '\n';
        }
    }

    // cout << "return 0";
}


