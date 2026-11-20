#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

string s;
int n;
set<string> ans;
bitset<10> used;
string cur;

void dfs(int id){
    if(used[id]) return;

    
    cur += s[id];
    used[id] = 1;
    
    if(cur.size() == n) ans.insert(cur);
    
    for(int i=0; i<n; i++){
        dfs(i);
    }
    

    cur.pop_back();
    used[id] = 0;
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>s;
    n = s.size();
    for(int i=0; i<n; i++) dfs(i);

    cout<<ans.size()<<'\n';
    for(auto x: ans){
        cout<<x<<'\n';
    }

}