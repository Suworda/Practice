#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 200005;
int n,k;
int a[N];
map<int,int> cnt;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }


    int l = 1;
    int kind = 0;
    int ans = 0;

    for(int r=1; r<=n; r++){
        cout << l << ' ' << r << '\n';
        if(cnt[a[r]] == 0) kind++;
        cnt[a[r]]++;

        while(kind > k){
            cnt[a[l]]--;

            if(cnt[a[l]] == 0){
                kind--;
            }

            l++;
        }

        ans += r-l+1;
    }

    cout << ans << '\n';
}











// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define ll long long

// const int N = 200005;
// int n,k;
// int a[N];
// map<int,int> cnt;

// signed main(){
//     // ios::sync_with_stdio(false);
//     // cin.tie(0);
    
//     cin>>n>>k;
//     for(int i=0; i<n; i++) cin>>a[i];

//     int ans = 0;
//     int l = 0;
//     int cur = 0;
//     for(int r=0; r<n; r++){
//         cur += (cnt[a[r]] == 0);
//         cnt[a[r]]++;

//         while(l+1 <= r && cur - (cnt[a[l+1]] == 1) >= k){
//             l++;
//             cur -= (cnt[a[l]] == 1);
//             cnt[l]--;
//         }

//         cout << l << ' ' << r << '\n';
//         if(cur >= k) ans += l+1;
//     }

//     cout << ans << '\n';
// }


