#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n,k;
    cin>>n>>k;
    if(k*2 <= n){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    for(int i=n; i>=k+1; i--){
        cout<<i<<' ';
    }
    for(int i=1; i<=k; i++){
        cout<<i<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}