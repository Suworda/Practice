#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Segt{
    #define l_id (id*2)
    #define r_id (id*2+1)

    struct Node{
        int len=0, sum=0;
        int set_tag=0, add_tag=0;
        bool has_set_tag = 0;

        void apply_set_tag(int x){
            sum = x * len;
            set_tag = x;
            has_set_tag = true;
            add_tag = 0;
        }

        void apply_add_tag(int x){
            sum += x * len;
            add_tag += x;
        }
    };

    int n;
    vector<Node> seg;

    Segt(const vector<int> &a): n(a.size()-1), seg(4*n+5){
        build(1, n, 1, a);
    }

    void pull(int id){
        seg[id].sum = seg[l_id].sum + seg[r_id].sum;
    }

    void push(int id){
        if(seg[id].len == 1) return;

        if(seg[id].has_set_tag){
            seg[l_id].apply_set_tag(seg[id].set_tag);
            seg[r_id].apply_set_tag(seg[id].set_tag);
            seg[id].has_set_tag = false;
        }

        if(seg[id].add_tag){
            seg[l_id].apply_add_tag(seg[id].add_tag);
            seg[r_id].apply_add_tag(seg[id].add_tag);
            seg[id].add_tag = 0;
        }
    }

    void build(int l, int r, int id, const vector<int> &a){
        seg[id].len = r - l + 1;

        if(l == r){
            seg[id].sum = a[l];
            return;
        }

        int m = (l+r)/2;
        build(l, m, l_id, a);
        build(m+1, r, r_id, a);
        pull(id);
    }

    void add(int l, int r, int ql, int qr, int x, int id){
        if(qr < l || r < ql) return;

        if(ql <= l && r <= qr){
            seg[id].apply_add_tag(x);
            return;
        }

        push(id);

        int m = (l+r)/2;
        add(l, m, ql, qr, x, l_id);
        add(m+1, r, ql, qr, x, r_id);
        pull(id);
    }

    void set(int l, int r, int ql, int qr, int x, int id){
        if(qr < l || r < ql) return;

        if(ql <= l && r <= qr){
            seg[id].apply_set_tag(x);
            return;
        }

        push(id);

        int m = (l+r)/2;
        set(l, m, ql, qr, x, l_id);
        set(m+1, r, ql, qr, x, r_id);
        pull(id);
    }

    int query(int l, int r, int ql, int qr, int id){
        if(qr < l || r < ql) return 0;
        
        if(ql <= l && r <= qr) return seg[id].sum;

        push(id);

        int m = (l+r)/2;
        int rst1 = query(l, m, ql, qr, l_id);
        int rst2 = query(m+1, r, ql, qr, r_id);
        return rst1 + rst2;
    }

    void add(int l, int r, int x){
        add(1, n, l, r, x, 1);
    }

    void set(int l, int r, int x){
        set(1, n, l, r, x, 1);
    }

    int query(int l, int r){
        return query(1, n, l, r, 1);
    }
};

#undef l_id
#undef r_id

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
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
            segt.add(l, r, x);
        }
        else if(ty == 2){
            int l, r, x;
            cin>>l>>r>>x;
            segt.set(l, r, x);
        }
        else{
            int l, r;
            cin>>l>>r;
            cout << segt.query(l, r) << '\n';
        }
    }

    // cout << "return 0";

}


