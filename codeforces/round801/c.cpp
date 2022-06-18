#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<bool> > b(n, vector<bool> (m));
        vector<vector<int> >mm(n, vector<int>(m, 0));
        vector<vector<int> >MM(n, vector<int>(m, 0));
        for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
            int num; cin >> num;
            b[i][j]=num==1;
        }
        mm[0][0]=MM[0][0]=b[0][0]==1;
        for(int i=1; i<m; ++i){
            mm[0][i]=mm[0][i-1]+b[0][i];
            MM[0][i]=MM[0][i-1]+b[0][i];
        }
        for(int i=1; i<n; ++i){
            mm[i][0]=mm[i-1][0]+b[i][0];
            MM[i][0]=MM[i-1][0]+b[i][0];
        }
        for(int i=1; i<n; ++i) {
            for(int j=1; j<m; ++j) {
                mm[i][j]=min(mm[i-1][j], mm[i][j-1])+b[i][j];
                MM[i][j]=max(MM[i-1][j], MM[i][j-1])+b[i][j];
            }
        }
        if((n+m)%2&&mm[n-1][m-1]<=(n+m)/2&&(n+m)/2<=MM[n-1][m-1])
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
}
