#include <bits/stdc++.h>
using namespace std;

int n,W;
int w[101], v[101];
long long dp[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>W;
    for(int i=1; i<=n; i++){
        cin>>w[i]>>v[i];
    }

    for(int i=1; i<=100000; i++){
        dp[i] = 2e9;
    }

    for(int i=1; i<=n; i++){
        for(int j=100000; j>=0; j--){
            if(j-v[i] >= 0) dp[j] = min(dp[j], dp[j-v[i]] + w[i]);
        }
    }

    int ans=0;
    for(int i=0; i<=100000; i++){
        if(dp[i] <= W) ans = max(ans, i);
    }

    cout<<ans<<'\n';

}