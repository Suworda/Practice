#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<int> ans(n+1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for(int i=1; i<=n; i++){
        while(pq.size() && a[i] >= pq.top().first+k){
            ans[pq.top().second] = i;
            pq.pop();
        }
        pq.push({a[i],i});
    }

    for(int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';

}


