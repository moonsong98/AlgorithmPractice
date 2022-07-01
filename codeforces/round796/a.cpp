#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        unsigned int n; cin >> n;
        int ans=0;
        if(n==1) ans=3;
        else {
            int cnt=0, m=100;
            for(int i=0; (1<<i)<=n; ++i )  {
                if((1<<i)&n) {
                    ++cnt;
                    m=min(m, i);
                }
            }
            if(cnt==1) ans=n+1;
            else ans=(1<<m);
        }
        cout << ans << '\n';
    }
}
