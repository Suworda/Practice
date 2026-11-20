#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
set<pair<int,int>> st;
int ans1 = 0;
int ans2 = 2e9;
vector<int> v[15];
int fact[15];

void dfs(int id, int x){
    // cerr<<id<<' '<<x<<'\n';
    if(id > m){
        ans2 = min(ans2, x);
        if(x > n){
            return;
        }
        ans1 += fact[n] / fact[n-x];
        return;
    }

    for(int i=1; i<=x; i++){
        bool ok = 1;
        for(int num: v[i]){
            if(st.count({id, num})) ok = 0;
        }
        if(ok){
            v[i].push_back(id);
            dfs(id+1, x);
            v[i].pop_back();

        }
    }

    v[x+1].push_back(id);
    dfs(id+1, x+1);
    v[x+1].pop_back();

    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for(int i=1; i<15; i++) fact[i] = fact[i-1] * i;
    
    cin>>m>>n;
    int a,b;
    while(cin>>a>>b){
        st.insert({a,b});
        st.insert({b,a});
    }

    dfs(1, 0);

    cout<<ans1<<'\n';
    cout<<ans2<<'\n';
}