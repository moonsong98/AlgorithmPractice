#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vector<int> v(N+2, 0);
    for(int i=1; i<=N; ++i) cin >> v[i];
    stack<int> s;
    s.push(0);
    int ans=0;
    for(int i=1; i<=N+1; ++i) {
        while(!s.empty()&&v[s.top()]>v[i]) {
            int pos=s.top(); s.pop();
            int h=v[pos], w=i-s.top()-1;
            ans=max(ans, h*w);
        }
        s.push(i);
    }
    cout << ans << '\n';
}
