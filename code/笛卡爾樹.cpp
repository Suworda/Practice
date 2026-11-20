#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long


struct Ctree {
    int n, root;
    vector<int> a;
    vector<int> lc, rc, pa;

    Ctree(int _n, const vector<int>& _a)
        : n(_n), root(0), a(_a),
          lc(n+1), rc(n+1), pa(n+1) {
        build();
    }

    void build(){
        vector<int> stk;

        for(int i=1; i<=n; i++){
            int last = 0;
            while(stk.size() && a[stk.back()] < a[i]){
                last = stk.back();
                stk.pop_back();
            }

            if(stk.size()){
                rc[stk.back()] = i;
                pa[i] = stk.back();
            }
            if(last){
                lc[i] = last;
                pa[last] = i;
            }

            stk.push_back(i);
            
        }

        root = stk.front();
    }
    
};


signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    

}


