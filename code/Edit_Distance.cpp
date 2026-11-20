#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int INF = 1e9;

int n, m;
string s, t;
int dp[5005][5005];
int mx[5005][5005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>s>>t;
    if(s.size() > t.size()) swap(s, t);
    n = s.size();
    m = t.size();
    s = ' ' + s;
    t = ' ' + t;

    for(int i=1; i<=n; i++) dp[i][0] = dp[i-1][0] + 1;
    for(int j=1; j<=m; j++) dp[0][j] = dp[0][j-1] + 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            
            if(s[i] == t[j]){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        }
    }

    cout << dp[n][m] << '\n';

}


