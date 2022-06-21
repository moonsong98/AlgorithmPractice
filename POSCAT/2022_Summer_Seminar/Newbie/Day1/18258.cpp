#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    deque<int> q;
    while(t--) {
        string cmd; cin >> cmd;
        if(cmd=="push") {
            int n; cin >> n;
            q.push_back(n);
        }
        else if(cmd=="pop") {
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop_front();
            }
        }
        else if(cmd=="size") cout << q.size() << '\n';
        else if(cmd=="empty") cout << q.empty() << '\n';
        else if(cmd=="front") cout << (q.empty() ? -1 : q.front()) << '\n';
        else if(cmd=="back") cout << (q.empty()?-1:q.back()) << '\n';
    }
}
