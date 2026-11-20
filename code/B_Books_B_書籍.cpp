#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 100005;
int n,t;
int a[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>t;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    int ans = 0;
    int cur = 0;
    int l = 1;
    for(int r=1; r<=n; r++){
        cur += a[r];

        while(cur > t){
            cur -= a[l];
            l++;
        }
        
        ans = max(ans, r-l+1);
    }



    cout << ans << '\n';
}

