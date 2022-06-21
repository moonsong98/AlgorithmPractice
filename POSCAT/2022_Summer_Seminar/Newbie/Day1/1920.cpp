#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for(int &num: v) cin >> num;
    sort(v.begin(), v.end());
    int t; cin >> t;
    while(t--) {
        int num; cin >> num;
        auto lb=lower_bound(v.begin(), v.end(), num);
        if(lb==v.end()||*lb!=num) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}
