#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        int n, m; cin >> n >> m;
        vector<int> t(n+1);
        for(int i=0; i<m; ++i) {
            int a; cin >> a;
            t[a]++;
        }
        int ans;
        int l=1, r=2*m;
        while(l<=r) {
            int mid=l+(r-l)/2;
            int left=m;
            for(int i=1; i<=n; ++i) {
                if(left<=0) break;
                if(mid<=t[i]) left-=mid;
                else {
                    int extra=(mid-t[i])/2;
                    left-=(t[i]+extra);
                }
            }
            if(left<=0) {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout << ans << '\n';
    }
}
