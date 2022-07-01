#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct juice {
    ll w, v;
};

ll gcd(ll a, ll b) {
    if(a>b) {
        ll tmp=a;
        a=b;
        b=tmp;
    }
    while(a) {
        ll tmp=b%a;
        b=a;
        a=tmp;
    }
    return b;
}

bool cmp(const juice &a, const juice &b) {
    return a.v*b.w>b.v*a.w;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<juice> juices(n);
    for(int i=0; i<n; ++i) 
        cin >> juices[i].w >> juices[i].v;
    sort(juices.begin(), juices.end(), cmp);
    ll sum=0, cur=0;
    for(; cur<n; ++cur) {
        if(m<juices[cur].w) break;
        sum+=juices[cur].v;
        m-=juices[cur].w;
    }
    if(m==0||cur==n) cout << sum << '/' << 1 << '\n';
    else {
        ll a=m*juices[cur].v, b=juices[cur].w, c=gcd(a, b);
        a/=c, b/=c;
        a+=b*sum;
        cout << a << '/' << b << '\n';
    }
}

