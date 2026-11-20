#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int N;
vector<pair<int,int>> ans;

void move(int n, int s, int t){
    if(n == 0) return;
    move(n-1, s, 6-s-t);
    ans.push_back({s,t});
    move(n-1, 6-s-t, t);
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>N;
    move(N,1,3);
    cout<<ans.size()<<'\n';
    for(auto [s,t]: ans) cout<<s<<' '<<t<<'\n';

}