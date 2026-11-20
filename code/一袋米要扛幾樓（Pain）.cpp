//樹 DP 解:
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define ll long long
// const ll INF = 2e18;
// using pii = pair<int,int>;

// struct Tree{
//     int n;
//     vector<vector<int>> nxt;
//     vector<vector<array<int,2>>> dp;
//     vector<int> val, sz, best;

//     Tree(int _n): n(_n), nxt(n+1), val(n+1), sz(n+1), best(n+1), dp(n+1, vector<array<int,2>>(n+1)){}

//     void add_edge(int a, int b){
//         nxt[a].push_back(b);
//         nxt[b].push_back(a);
//     }

//     void set_dp(){
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=n; j++){
//                 for(int k=0; k<2; k++){
//                     dp[i][j][k] = -INF;
//                 }
//             }
//         }
//         auto dfs = [&](auto &&dfs, int u, int pa) -> void {
//             dp[u][1][0] = dp[u][1][1] = val[u];
//             sz[u] = 1;

//             for(int v: nxt[u]){
//                 if(v == pa) continue;

//                 dfs(dfs, v, u);
                
//                 for(int i=1; i<=sz[u]; i++){
//                     for(int j=1; j<=sz[v]; j++){
//                         dp[u][i+j][1] = max(dp[u][i+j][1], dp[u][i][0] + dp[v][j][0]);
//                     }
//                 }
                
//                 for(int j=2; j<=n; j++) dp[u][j][0] = max(dp[u][j][0], dp[v][j-1][0] + val[u]);
                
//                 sz[u] += sz[v];
//             }
//         };

//         dfs(dfs,1, 0);

//         best[0] = -INF;
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=n; j++){
//                 best[j] = max(best[j], dp[i][j][1]);
//             }
//         }
//         for(int i=1; i<=n; i++) best[i] = max(best[i], best[i-1]);
//     }

//     void test(){
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=n; j++){
//                 cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' <<dp[i][j][1] << '\n';
//             }
//         }
//     }

//     optional<int> query(int k){
//         auto it = lower_bound(best.begin()+1, best.end(), k);
//         if(it == best.end()) return nullopt;
//         return (it - best.begin());
//     }
// };

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     int n,q;
//     cin>>n>>q;
//     Tree tree(n);
//     for(int i=1; i<=n; i++) cin>>tree.val[i];

//     for(int i=0; i<n-1; i++){
//         int a, b;
//         cin>>a>>b;
//         tree.add_edge(a, b);
//     }

//     tree.set_dp();

//     while(q--){
//         int k;
//         cin>>k;
//         auto ans = tree.query(k);
//         if(ans) cout << *ans << '\n';
//         else cout << "Shinra Tensei\n";
//     }
// }

// 暴力枚舉解:
#include <bits/stdc++.h>>
using namespace std;
#define int long long
#define ll long long
const ll INF = 2e15;

struct Tree{
    int n;
    vector<vector<int>> nxt;
    vector<int> val;
    vector<int> best;
    
    Tree(int _n): n(_n), val(n+1), nxt(n+1), best(n+1, -INF) {}

    void add_edge(int a, int b){
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }

    void preset(){
        auto dfs = [&](auto &&dfs, int u, int pa, int len, int cur_v) -> void {
            best[len] = max(best[len], cur_v);

            for(int v: nxt[u]){
                if(v == pa) continue;
                dfs(dfs, v, u, len+1, cur_v+val[v]);
            }
        };

        for(int i=1; i<=n; i++) dfs(dfs, i, 0, 1, val[i]);
        for(int i=1; i<=n; i++) best[i] = max(best[i], best[i-1]);

    }

    optional<ll> query(int k){
        auto it = lower_bound(best.begin()+1, best.end(), k);

        if(it == best.end()) return nullopt;
        return (it - best.begin());
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin>>n>>q;

    Tree tree(n);

    for(int i=1; i<=n; i++) cin>>tree.val[i];
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        tree.add_edge(a,b);
    }

    tree.preset();

    while(q--){
        int k;
        cin>>k;
        auto ans = tree.query(k);
        if(ans) cout << *ans << '\n';
        else cout << "Shinra Tensei\n";
    }

}