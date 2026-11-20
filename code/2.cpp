#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int N,M;
int all;
int ans;
bitset<20> slape, bslape, col;
int m_slape[20], m_bslape[20];

void dfs(int id, int n, int m){
    // cerr<<id<<' '<<n<<' '<<m<<'\n';
    if(id > all){
        ans++;
        return;
    }
    if(n){
        for(int j=1; j<=all; j++){
            if(!slape[id+j] && !bslape[id-j+all] && !col[j] && !m_slape[id+j] && !m_bslape[id-j+all]){
                slape[id+j] = 1;
                bslape[id-j+all] = 1;
                col[j] = 1;
                dfs(id+1, n-1, m);
                slape[id+j] = 0;
                bslape[id-j+all] = 0;
                col[j] = 0;
            }
        }
    }

    if(m){
        for(int j=1; j<=all; j++){
            if(!slape[id+j] && !bslape[id-j+all] && !col[j]){
                col[j] = 1;
                m_slape[id+j]++;
                m_bslape[id-j+all]++;
                dfs(id+1, n, m-1);
                col[j] = 0;
                m_slape[id+j]--;
                m_bslape[id-j+all]--;

            }
        }
    }
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>N>>M;
    all = N+M;
    dfs(1,N,M);
    cout<<ans<<'\n';
}