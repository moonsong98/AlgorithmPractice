#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<int> v(n);
    vector<int> dp;
    for(int &num: v) cin >> num;
    for(int i=0; i<n; ++i) {
        auto lb=lower_bound(dp.begin(), dp.end(),v[i]);
        if(lb==dp.end()) dp.push_back(v[i]);
        else if(*lb==v[i]) continue;
        else if(lb==dp.begin()) dp[0]=v[i];
        else *lb=v[i];
    }
    cout << (int)dp.size() << '\n';
}

