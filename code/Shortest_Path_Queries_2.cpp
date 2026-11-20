#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll INF = 1e15;

int n, m;
int dp[405][405];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = INF;
            if(i == j) dp[i][j] = 0;
        }
    }

    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        dp[a][b] = c;
    }
    
    int ans = 0;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                ans += (dp[i][j] < INF ? dp[i][j] : 0);
            }
        }
    }

    cout << ans << '\n';
}


