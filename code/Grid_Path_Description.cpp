#include <bits/stdc++.h>
using namespace std;

string s;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int dir[50];
bool vis[9][9];
int ans;

void dfs(int r, int c, int x){
    vis[r][c] = 1;

    if(r == 7 && c == 1){
        if(x == 48) ans++;
        vis[r][c] = 0;
        return;
    }
    
    if(vis[r][c+1] && vis[r][c-1] && !vis[r+1][c] && !vis[r-1][c]){
        vis[r][c] = 0;
        return;
    }
    if(!vis[r][c+1] && !vis[r][c-1] && vis[r+1][c] && vis[r-1][c]){
        vis[r][c] = 0;
        return;
    }

    if(s[x] != '?'){
        int nr = r+dr[dir[x]];
        int nc = c+dc[dir[x]];
        if(!vis[nr][nc]) dfs(nr,nc,x+1);

    }else{
        if (!vis[r-1][c]) dfs(r-1, c, x + 1);
        if (!vis[r+1][c]) dfs(r+1, c, x + 1);
        if (!vis[r][c-1]) dfs(r, c-1, x + 1);
        if (!vis[r][c+1]) dfs(r, c+1, x + 1);
    }

    vis[r][c] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<=8; i++){
        vis[i][0] = vis[0][i] = vis[8][i] = vis[i][8] = 1;
    }

    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'U') dir[i] = 0;
        else if(s[i] == 'D') dir[i] = 1;
        else if(s[i] == 'L') dir[i] = 2;
        else if(s[i] == 'R') dir[i] = 3;
        else dir[i] = -1;
    }

    dfs(1,1,0);

    cout<<ans<<'\n';

}