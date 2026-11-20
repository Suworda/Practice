#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int x;
multiset<int> last;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ans=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        auto it = last.lower_bound(x);

        if(it == last.begin()) ans++;
        else last.erase(--it);

        last.insert(x);
    }
    cout<<ans<<'\n';
}