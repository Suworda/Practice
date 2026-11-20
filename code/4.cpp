#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
vector<int> nxt[100005];
int dp[100005];

int dfs(int u){
    if(dp[u] != -1) return dp[u];
    int rst = 0;
    for(int v: nxt[u]) rst = max(rst, dfs(v)+1);
    return dp[u] = rst; 
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        nxt[x].push_back(y);
    }

    int ans = 0;
    for(int i=1; i<=n; i++) ans = max(ans, dfs(i)); 

    cout<<ans<<'\n';

}