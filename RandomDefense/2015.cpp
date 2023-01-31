#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K; cin >> N >> K;
    long long ans = 0;
    vector<int> pSum(N+1, 0);
    map<int, int> cnt; cnt[0] = 1;
    for(int i=1; i<=N; ++i) {
        int a; cin >> a;
        pSum[i] = pSum[i-1] + a;
        ans += (long long) cnt[pSum[i] - K];
        cnt[pSum[i]]++;
    }
    cout << ans << '\n';
}
