#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

pair<int,int> exgcd(int a, int b){
    if(b == 0) return {a >= 0 ? 1 : -1, 0};

    auto [x, y] = exgcd(b, a%b);
    return {y, x - (a/b)*y};
}

optional<pair<int,int>> exgcd(int a, int b, int c){
    if(a == 0 && b == 0){
        if(c == 0) return pair<int,int> {0, 0};
        return nullopt;
    }

    int g = gcd(a, b);
    if(c % g != 0) return nullopt;

    auto [x, y] = exgcd(a, b);
    return pair<int,int> {x*(c/g), y*(c/g)};
}

struct Query{
    int r, m;

    Query operator+ (const Query &other) const{
        int g = gcd(m, other.m);
        int a = m;
        int b = -other.m;
        int c = other.r - r;
        
        auto [x, y] = exgcd(a, b);
        int mod = other.m / g;
        int k = (x%mod) * (c/g%mod) % mod;
        
        Query rst = {r + m*k, m*other.m/g};

        rst.r %= rst.m;
        if(rst.r < 0) rst.r += rst.m;
        return rst;
    }

};

bool valid(Query a, Query b){
    return (b.r - a.r) % gcd(a.m, -b.m) == 0;
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    vector<Query> q;
    for(int i=0; i<n; i++){
        int r, m;
        cin>>r>>m;
        q.push_back({r, m});
    }

    Query cur = q[0];

    for(int i=1; i<n; i++){
        if(!valid(cur, q[i])){
            cout << -1 << '\n';
            return 0;
        }
        cur = cur + q[i];
    }

    cout << cur.r << '\n';



}


