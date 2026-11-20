#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m,k;
int x, y;
int a[200005], b[200005];
int a_sum[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>k;
    cin>>x>>y;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=m; i++) cin>>b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    for(int i=1; i<=n; i++) a_sum[i] = a_sum[i-1] + a[i];

    int cur = x+y*k;
    int ry = y;
    int ans = 0;
    for(int i=0; i<=m; i++){
        ry -= b[i] / k + (b[i]%k != 0);
        if(ry < 0) break;
        cur -= b[i];

        auto it = upper_bound(a_sum, a_sum+n+1, cur);
        ans = max(ans, it - a_sum + i - 1);
    }

    cout << ans << '\n';
}


