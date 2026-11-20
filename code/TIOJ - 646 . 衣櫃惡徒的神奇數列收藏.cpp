#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int a[1000005];
pair<int,int> ans;
int mx = 0;

void upd_ans(int l, int r){
    if(r - l + 1 > mx){
        mx = r-l+1;
        ans = {l,r};
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int l = 0;
    unordered_set<int> st;
    for(int r=0; r<n; r++){
        bool good = st.insert(a[r]).second;
        while(!good){
            if(a[l] == a[r]){
                good = 1;
                l++;
                break;
            }
            st.erase(a[l]);
            l++;
        }

        upd_ans(l,r);
    }

    for(int i=ans.first; i<=ans.second; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';

}


