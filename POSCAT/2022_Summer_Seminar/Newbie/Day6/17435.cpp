#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int M, Q; cin >> M;
    vector<vector<int>> cache(M+1, vector<int>(20));
    for(int i=1; i<=M; ++i) cin >> cache[i][0];
    for(int j=1; j<20; ++j)
        for(int i=1; i<=M; ++i)
            cache[i][j]=cache[cache[i][j-1]][j-1];
    cin >> Q;
    while(Q--) {
        int n, x, cnt=0; cin >> n >> x;
        while(n) {
            if(n%2)
                x=cache[x][cnt];
            ++cnt;
            n>>=1;
        }
        cout << x <<'\n';
    }
}
