#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        int num=0;
        for(int i=0; i<4; ++i) {
            int a; cin >> a;
            num+=a;
        }
        if(num==0) cout << 0 <<'\n';
        else if (num==4) cout << 2 << '\n';
        else cout << 1 << '\n';
    }
}
