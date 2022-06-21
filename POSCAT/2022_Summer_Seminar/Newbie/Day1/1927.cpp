#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    priority_queue<int> pq;
    for(int i=0; i<n; ++i) {
        int cmd; cin >> cmd;
        if(cmd>0) pq.push(-cmd);
        else {
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << -pq.top() << '\n';
                pq.pop();
            }
        }
    }
}
