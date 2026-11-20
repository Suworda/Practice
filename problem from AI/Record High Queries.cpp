#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Query{
    int r, h;
};

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n, q;
    cin>>n>>q;
    vector<int> a(n+1);

    for(int i=1; i<=n; i++) cin>>a[i];

    vector<Query> Q;
    for(int i=1; i<=q; i++){
        int r, h;
        cin>>r>>h;
        Q.push_back({r, h});
    }

    vector<int> stk;
    int q_id = 0;

    for(int i=1; i<=n; i++){
        while(stk.size() && stk.back() <= a[i]){
            stk.pop_back();
        }

        stk.push_back(a[i]);

        while(q_id < q && Q[q_id].r == i){
            auto [r, h] = Q[q_id++];
            auto it = upper_bound(stk.begin(), stk.end(), h, greater<>());

            // for(int x: stk) cout << x << ' ';
            // cout << '\n';
            // cout << stk.end() - it << '\n';
            cout << it - stk.begin() << '\n';
        }
    }

}


