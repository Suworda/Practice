#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
string s;
int cnt[128];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>s;
    int k = 0;
    for(int i=0; i<n; i++){
        if(cnt[s[i]] == 0) k++;
        cnt[s[i]]++;
    }

    for(int i=0; i<128; i++) cnt[i] = 0;

    int ans = 2e9;
    int cur = 0;
    int l = 0;
    for(int r=0; r<n; r++){
        cur += (cnt[s[r]] == 0);
        cnt[s[r]]++;
        //add(s[r])

        while(cur == k){
            ans = min(ans, r-l+1);
            cur -= (cnt[s[l]] == 1);
            cnt[s[l]]--;
            // remove(s[l])
            l++;
        }
    }

    cout << ans << '\n';

}


