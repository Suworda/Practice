#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, s;
bool a[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>s;
    int l = 2e9, r = -2e9;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(a[i] == 0){
            l = min(l, i);
            r = max(r, i);
        }
    }

    if(l == 2e9 || r == -2e9){
        cout << 0 << '\n';
        return 0;
    }
    
    l = min(l, s+1);
    r = max(r, s);

    int ans = 0;
    for(int i=l; i<=r; i++) ans += (a[i] == 1);
    cout << ans + (r - l + 1) << '\n';
}
