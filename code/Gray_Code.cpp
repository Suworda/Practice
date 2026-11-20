#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int N;
vector<string> ans;
void dfs(int n){
    if(n == 1){
        ans.push_back("0");
        ans.push_back("1");
        return;
    }
    dfs(n-1);
    int m = ans.size();
    for(int i=m-1; i>=0; i--) ans.push_back(ans[i]);
    for(int i=0; i<ans.size(); i++) ans[i] += '0' + (i >= m);
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int N;
    cin>>N;
    dfs(N);

    for(string s: ans) cout<<s<<'\n';

}