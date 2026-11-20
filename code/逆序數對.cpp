#include <bits/stdc++.h>
using namespace std;
#define int long long

struct BIT{
    int n;
    vector<int> b;

    BIT(int _n): n(_n), b(n+5) {}

    void upd(int x, int v){
        while(x <= n){
            b[x] += v;
            x += x & -x;
        }
    }

    int query(int x){
        int rst = 0;
        while(x){
            rst += b[x];
            x -= x & -x;
        }
        return rst;
    }

    int query(int l, int r){
        return query(r) - query(l-1);
    }
};

int get_ans(vector<int> &a, int n){
    int ans = 0;
    BIT seen(n);

    for(int i=0; i<n; i++){
        int x = a[i];
        ans += seen.query(x+1, n);
        seen.upd(x, +1);
    }

    return ans;
}

vector<int> dst(vector<int> &a){
    int n = a.size();
    vector<int> rst;

    vector<int> d = a;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());

    for(int i=0; i<n; i++){
        int x = lower_bound(d.begin(), d.end(), a[i]) - d.begin() + 1;
        rst.push_back(x);
    }

    return rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 0;
    int n;
    while(cin>>n && n != 0){
        t++;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
            a[i]++;
        }

        vector<int> v = dst(a);
        
        int ans = get_ans(v, n);
        
        cout << "Case #" << t << ": " << ans << '\n';
    }
}
