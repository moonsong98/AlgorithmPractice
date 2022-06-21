#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for(int &num: v) cin >> num;
    stack<int> s;
    vector<int> ans;
    for(int i=n-1; i>=0; --i) {
        while(!s.empty()&&s.top()<=v[i]) s.pop();
        ans.push_back(s.empty()?-1:s.top());
        s.push(v[i]);
    }
    reverse(ans.begin(), ans.end());
    for(int num: ans) cout << num << ' ';
    cout << '\n';
}
