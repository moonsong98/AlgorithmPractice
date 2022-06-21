#include<bits/stdc++.h>
using namespace std;

struct point {
    int f, s;
};

bool operator < (const point &a, const point &b) {
    if(a.f==b.f) return a.s<b.s;
    return a.f<b.f;
}

int main(void) {
    int n;
    cin >> n;
    vector<point> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i].f >> v[i].s;
    sort(v.begin(), v.end());
    for(auto p: v)
        cout << p.f << ' ' << p.s << '\n';
}
