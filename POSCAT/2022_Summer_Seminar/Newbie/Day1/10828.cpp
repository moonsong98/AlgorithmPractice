#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    stack<int> s;
    while(t--) {
        string cmd; cin >> cmd;
        if(cmd=="push") {
            int n; cin >> n;
            s.push(n);
        }
        if(cmd=="pop" || cmd=="top") {
            if(s.empty()) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                if(cmd=="pop")
                    s.pop();
            }
        }
        if(cmd=="size") 
            cout << s.size() << '\n';
        if(cmd=="empty")
            cout << s.empty() << '\n';
    }
}
