#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> k;
        vector<pair<int,ll> > a, b;
        for(int i=0; i<n; ++i) {
            int num;
            ll cnt=1;
            cin >> num;
            while(num%k==0) {
                cnt*=k;
                num/=k;
            }
            if(a.empty()||a.back().first!=num)
                a.push_back({num, cnt});
            else
                a.back().second+=cnt;
        }
        cin >> m;
        for(int i=0; i<m; ++i) {
            int num;
            ll cnt=1;
            cin >> num;
            while(num%k==0) {
                cnt*=k;
                num/=k;
            }
            if(b.empty()||b.back().first!=num)
                b.push_back({num, cnt});
            else
                b.back().second+=cnt;
        }
        bool ans=sz(a)==sz(b);
        if(!ans) {
            cout << "No" << '\n';
            continue;
        }
        for(int i=0; i<sz(a); ++i)
            if(a[i]!=b[i]) {
                ans=false;
                break;
            }
        cout << (ans?"Yes":"No") << '\n';
    }
}
