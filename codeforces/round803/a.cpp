#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; ++i)
            cin >> v[i];
        int ans;
        for(int i=0; i<n; ++i) {
            int cand=v[i];
            int a=-1;
            for(int j=0; j<n; ++j) {
                if(j==i) continue;
                if(a==-1) a=v[j];
                else a^=v[j];
            }
            if(cand==a)
                ans=cand;
        }
        cout << ans << '\n';
    }
}
