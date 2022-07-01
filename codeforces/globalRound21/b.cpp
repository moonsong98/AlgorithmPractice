#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int &num: v) cin >> num;
        int ans=0;
        for(int i=0; i<n; ++i) {
            if(v[i]!=0) {
                for(; i<n; ++i) 
                    if(v[i]==0) break;
                ++ans;
                --i;
            }
        }
        cout << min(ans, 2) << '\n';
    }
}
