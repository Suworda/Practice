#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[100005];
int w[101],v[101];
int n,W;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>W;
    for(int i=1; i<=n; i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=W; j>=0; j--){
            if(j-w[i] >= 0) dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }

    cout<<dp[W]<<'\n';
    

}