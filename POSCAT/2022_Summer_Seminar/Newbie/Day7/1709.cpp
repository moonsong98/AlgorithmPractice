#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    int N, cnt=0; cin >> N;
    ll half=(ll)N/2, curY=half, prevY;
    auto isValid=[&](ll x, ll y)->bool {
        return (x-1)*(x-1)+(y-1)*(y-1)<half*half && half*half <(x*x)+(y*y);
    };
    for(ll x=1; x<=half; ++x) {
        while(!isValid(x, curY)) --curY;
        while(isValid(x, curY)&&curY) {
            ++cnt;
            if(!isValid(x,curY-1)) break;
            --curY;
        }
    }
    cout << cnt*4 <<'\n';
}
