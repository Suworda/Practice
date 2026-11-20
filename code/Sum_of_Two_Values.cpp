#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 200005;
int n,x;
vector<pair<int,int>> v;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>x;
    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        v.push_back({val, i+1});
    }

    sort(v.begin(), v.end());

    int l=0;
    int r=n-1;
    while(l < r){
        int sum = v[l].first + v[r].first; 
        if(sum == x){
            cout << v[l].second << ' ' << v[r].second << '\n';
            return 0;
        }
        else{
            if(sum < x) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE\n";
    


}