#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 1e9+7;

struct Graph{
    int n;
    vector<vector<int>> nxt;
    vector<vector<int>> pre;
    vector<int> dp;

    Graph(int _n): n(_n), nxt(n+1), pre(n+1) {}

    void add_edge(int a, int b){
        nxt[a].push_back(b);
        pre[b].push_back(a);
    }

    int get_ans(){
        vector<bool> vis(n+1);
        auto dfs = [&](auto &&dfs, int u) -> void {
            if(vis[u]) return;
            if(u == 1) return;
        ]
            vis[u] = 1;
            for(int v: pre[u]){
                dfs(dfs,v);
                dp[u] += dp[v];
                dp[u] %= M;
            }
        };
        
        dp[1] = 1;
        vis[1] = 1;
        // dfs(dfs, n);

        return dp[n];
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;

    Graph g(n);

    while(m--){
        int a, b;
        cin>>a>>b;
        g.add_edge(a, b);
    }

    int ans = g.get_ans();

    cout << "return 0";
}