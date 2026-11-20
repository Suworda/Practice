#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

int x,y,a,b;
bool valid(int tg){
    int d = abs(a-b), cur = 0, base = min(a,b);

    if(d == 0) return min(x/a, y/b) >= tg;

    int X = x;
    int Y = y;
    X -= base*tg;
    Y -= base*tg;
    if(X < 0 || Y < 0) return false;

    cur += X/d + Y/d;

    //cout<<tg<<' '<<cur<<'\n';
    return cur >= tg;
    

}

void sol(){
    cin>>x>>y>>a>>b;

    int ans;
    int l=0, r=1e9;
    while(l <= r){
        int mid = (l+r)/2;
        if(valid(mid)){
            ans = mid;
            l = mid+1;

        }else{
            r = mid-1;
        }
    }

    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}