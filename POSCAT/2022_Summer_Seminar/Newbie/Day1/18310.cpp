#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    cout << v[(n-1)/2] << '\n';
}
/*
int main(void) {
    int n; cin >> n;
    vector<long long>v(n);
    vector<long long> pSum(n+1);
    for(int i=0; i<n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=1; i<=n; ++i)
        pSum[i]=pSum[i-1]+v[i-1];
    long long m=1e12, pos=-1;
    for(int i=1; i<=n; ++i) {
        long long cur=(i*2-n-1)*v[i-1]+pSum[n]-pSum[i]-pSum[i-1];
        if(cur<m) {
            m=cur;
            pos=i;
        }
    }
    cout << v[pos-1] << '\n';
}
*/
