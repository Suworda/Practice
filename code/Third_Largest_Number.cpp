#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    multiset<int, greater<int>> mst;
    int x;
    cin>>x;
    mst.insert(x);
    cin>>x;
    mst.insert(x);
    
    for(int i=2; i<n; i++){
        cin>>x;
        mst.insert(x);
        cout << *next(next(mst.begin())) << '\n';
    }

}


