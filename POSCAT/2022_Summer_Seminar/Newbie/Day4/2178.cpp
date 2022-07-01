#include<bits/stdc++.h>
using namespace std;

struct POS {
    int y, x;
};

int dy[]={1,0,-1,0}, dx[]={0,1,0,-1};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int> > dist(n, vector<int>(m, -1));
    vector<vector<bool> > board(n, vector<bool>(m, false));
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
        char ch; cin >> ch;
        board[i][j]=ch-'0';
    }
    queue<POS> q;
    q.push({0, 0});
    dist[0][0]=1;
    auto inBound=[=](int y, int x)->bool {
        return 0<=y&&y<n&&0<=x&&x<m;
    };
    while(!q.empty()) {
        int y=q.front().y, x=q.front().x, cur=dist[y][x];
        q.pop();
        for(int i=0; i<4; ++i) {
            int ny=y+dy[i], nx=x+dx[i];
            if(inBound(ny, nx)&&board[ny][nx]&&dist[ny][nx]==-1) {
                dist[ny][nx]=cur+1;
                q.push({ny, nx});
            }
        }
    }
    cout << dist[n-1][m-1] << '\n';
}
