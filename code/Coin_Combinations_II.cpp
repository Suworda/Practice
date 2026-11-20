#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int M = 1e9+7;
int n, x;
int a[1000001];
int dp[101][1000001];

void add(int &x, int y){
    ll t = x + y;
    x = t%M;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>x;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            dp[i][j] = dp[i-1][j];
            if(j - a[i] >= 0) add(dp[i][j], dp[i][j-a[i]]);

        }
    }
    
    cout << dp[n][x] << '\n';
} 