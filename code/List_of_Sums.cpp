#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int all;
int b[5005];
int a[105];

void try1(){
    multiset<int> mst;
    for(int i=1; i<=all; i++) mst.insert(b[i]);
    mst.erase(mst.find(a[1] + a[2]));
    mst.erase(mst.find(a[2] + a[3]));
    mst.erase(mst.find(a[1] + a[3]));
    
    for(int i=4; i<=n; i++){
        a[i] = *mst.begin() - a[1];
        for(int j=1; j<i; j++){
            if(mst.find(a[i] + a[j]) == mst.end()) return;
            mst.erase(mst.find(a[i] + a[j]));
        }
            
    }

    for(int i=1; i<=n; i++) cout<<a[i]<<' ';
    cout<<'\n';
    exit(0);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    all = n*(n-1)/2;
    for(int i=1; i<=all; i++){
        cin>>b[i];
    }
    sort(b+1, b+all+1);

    for(int i=3; i<=n; i++){
        int S = b[1] + b[2] + b[i];
        if(S%2 == 1) continue;

        int s = S/2;
        a[1] = s - b[i];
        a[2] = s - b[2];
        a[3] = s - b[1];

        try1();
    }
    // b1 = a1 + a2
    // b2 = a1 + a3
    // bi = a2 + a3
    // S = b1 + b2 + bi
    // s = S/2
    // a1 = s - bi
    // a2 = s - b2
    // a3 = s - b1


}