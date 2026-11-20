#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int stk[200005];
int sn=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    stk[sn++] = 0;
    for(int i=1; i<=n; i++){
        while(a[i] < a[stk[sn-1]]){
            sn--;
        }
        cout<<stk[sn-1]<<' ';
        stk[sn++] = i;
    }
}