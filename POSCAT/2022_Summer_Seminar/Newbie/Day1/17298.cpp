#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<int> v(n);
    stack<int> s;
    for(int i=0; i<n; ++i) cin >> v[i];
    for(int i=n-1; i>=0; --i) {
        while(!s.empty()&&s.top()<=v[i])
            s.pop();
        s.push(v[i]);
    }
}
