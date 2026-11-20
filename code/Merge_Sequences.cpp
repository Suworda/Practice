#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
int a[100005], b[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }

    vector<int> c(n), d(m);
    
    int p1 = 0;
    int p2 = 0;
    int id = 1;

    while(p1 < n && p2 < m){
        if(a[p1] < b[p2]){
            c[p1] = id;
            p1++;
        }else{
            d[p2] = id;
            p2++;
        }
        id++;
    }

    while(p1 < n) c[p1++] = id++;
    while(p2 < m) d[p2++] = id++;

    for(int i=0; i<n; i++) cout << c[i] << ' ';
    cout << '\n';
    for(int i=0; i<m; i++) cout << d[i] << ' ';


}