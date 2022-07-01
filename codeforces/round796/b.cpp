#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v; 
        for(int i=0; i<n; ++i) {
            int num; cin >> num;
            if(num%2==0) v.push_back(num);
        }
        int m=100;
        for(int &num: v) {
            for(int i=1; (1<<i)<=num; ++i) 
                if(num&(1<<i)) {
                    num=i;
                    m=min(m, i);
                    break;
                }
        }
        if(sz(v)<n) 
            cout << sz(v) << '\n';
        else 
            cout << sz(v)-1+m << '\n';
    }
}
