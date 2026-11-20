#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int q, v;
    cin>>q>>v;
    priority_queue<int> pq;
    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int t, w;
            cin>>t>>w;
            pq.push(w-t);
        }
        else{
            int t;
            cin>>t;
            if(pq.empty()){
                cout << -1 << '\n';
                continue;
            }
            auto a = pq.top(); pq.pop();
            cout << min(v, a + t) << '\n';
        }
    }
}
