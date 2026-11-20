#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

pair<int,int> _exgcd(int a, int b){
    if(b == 0) return {1, 0};
    auto [_x, _y] = _exgcd(b, a%b);
    return {_y, _x - a/b*_y};
}

pair<int,int> exgcd(int a, int b, int c){
    int g = gcd(a, b);
    if(c % g != 0){
        return {-1,-1};
    } 

    int x = (a >= 0 ? 1 : -1);
    int y = (b >= 0 ? 1 : -1);

    a = abs(a);
    b = abs(b);

    auto [_x, _y] = _exgcd(a, b);

    x *= _x;
    y *= _y;

    return {x*(c/g), y*(c/g)};

}

int power(int a, int b, int M){
    if(b == 0) return 1;

    int m = power(a, b/2, M);
    if(b & 1) return m*m%M*a%M;
    else return m*m%M;
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int p, q, e, c;
    cin >> p >> q >> e >> c;

    int n = p*q;
    int phi_n = (p-1) * (q-1);

    int b = -phi_n;
    int a = e;

    int d = exgcd(a, b, 1).first;

    while(d < 0) d += phi_n;

    cout << power(c, d, n) << '\n';


}


