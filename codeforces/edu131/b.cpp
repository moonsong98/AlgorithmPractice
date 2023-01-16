#include<bits/stdc++.h>
using namespace std;

int main(void) { 
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        cout << 2 << '\n';
        vector<int> perm(1,1);
        vector<int> isAdded(n+1, false); isAdded[0]=isAdded[1]=true;
        for(int i=1; i<=n; ++i) {
            for(int j=i; j<=n; j*=2) 
                if(isAdded[j]==false) {
                    perm.push_back(j);
                    isAdded[j]=true;
                }
        }
        for(int num: perm) cout << num << ' ';
        cout << '\n';
    }
}
