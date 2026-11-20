#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int nxt[32];
int pre[32];
vector<int> ans;
int cnt;

void upd(int cur, int id){
    while(id <= n){
        ans[id++] = cur;
        cur = nxt[cur]; 
    }
}

void dfs(int x){
    if(x > n){
        cnt++;
        int cur = 0;
        int id = 1;
        while(cur != 1){
            cur = nxt[cur];
            if(cur > ans[id]){
                upd(cur, id);
                return;
            }else if(cur < ans[id]){
                return;
            }
            id++;
        }
        return;
    }

    for(int a=0; a<x; a++){
        if(a == 1) continue;
        int b = nxt[a];
        int y = a + b;
        if(x >= y && x%y == 0){
            pre[b] = x;
            nxt[a] = x;
            pre[x] = a;
            nxt[x] = b;
            dfs(x+1);
            pre[b] = a;
            nxt[a] = b;
        }
    }


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    nxt[0] = 1;
    pre[1] = 0;
    ans.resize(n+1);
    dfs(2);

    cout<<cnt<<'\n';
    for(int x: ans) cout<<x<<' ';
    cout<<'\n';
}