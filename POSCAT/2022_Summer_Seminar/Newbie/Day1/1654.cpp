#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int k, n; cin >> k >> n;
    long long l=1, r=-1; 
    vector<long long> v(k);
    for(int i=0; i<k; ++i) {
        cin >> v[i];
        r=max(r, v[i]);
    }
    int ans=-1;
    while(l<=r) {
        long long len=l+(r-l)/2;
        long long cnt=0;
        for(int i=0; i<k; ++i) cnt+=v[i]/len;
        if(cnt>=n) {
            ans=len;
            l=len+1;
        }
        else r=len-1;
    }
    cout << ans << '\n';
}
