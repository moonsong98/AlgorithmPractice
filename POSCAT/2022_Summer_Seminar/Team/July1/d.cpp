#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed;
    cout.precision(16);
    int n; cin >> n;
    vector<double> p(n);
    double ans=0;
    for(int i=0; i<n; ++i) cin >> p[i];
    for(int i=0; i+1<n; ++i) 
        ans+=(p[i]+p[i]*(1-p[i+1])+(1-p[i])*p[i+1]);
    ans+=p[n-1];
    cout << ans << '\n';
}
