#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int a[5005];
int dp[5005][5005];
int sum[5005];
bool vis[5005][5005];

int SUM(int l, int r){
    return sum[r] - sum[l-1];
}

int f(int l, int r){
    if(l == r) return a[l];
    if(vis[l][r]) return dp[l][r];
    vis[l][r] = 1;

    ll rst = -2e18;
    return dp[l][r] = max({
        a[l] + (SUM(l+1, r) - f(l+1, r)),
        a[r] + (SUM(l, r-1) - f(l, r-1))
    });

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }

    cout << f(1, n) <<'\n';
}