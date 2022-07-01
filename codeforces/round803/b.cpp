#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >>t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for(int i=0; i<n; ++i)
            cin >>v[i];
        if(k==1) cout << (n-1)/2 << '\n';
        else {
            int ans=0;
            for(int i=1; i+1<n; ++i) {
                if(v[i]>v[i-1]+v[i+1])
                    ++ans;
            }
            cout << ans << '\n';
        }
    }
}
