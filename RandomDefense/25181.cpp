#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vector<pii> A(N);
    bool valid = true;
    map<int, int> cnt;
    for(int i=0; i<N; ++i){
        cin >> A[i].first;
        cnt[A[i].first]++;
        A[i].second = i;
        if(cnt[A[i].first] > N/2)
            valid = false;
    }
    if(!valid) {
        cout << -1 << '\n';
        return 0;
    }
    sort(A.begin(), A.end(), [](pii a, pii b) -> bool {
            return a.first < b.first;
            });

    auto swap = [](pii &a, pii &b) {
        int tmp = a.first; a.first = b.first; b.first = tmp;
    };

    for(int i=0; i<N/2; ++i)
        swap(A[i], A[i+N/2]);

    if(N%2)
        swap(A[N/2], A[N-1]);

    sort(A.begin(), A.end(), [](pii a, pii b) -> bool {
            return a.second < b.second;
            });
    for(pii a: A)
        cout << a.first << ' ';
    cout << '\n';
}
