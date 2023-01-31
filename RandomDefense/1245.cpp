#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int dy[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dx[] = {1, -1, 0, 1, -1, 0 , 1, -1};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, ans=0; cin >> n >> m;
    vector<vector<int>> board(n ,vector<int>(m));
    vector<vector<int>> discovered(n ,vector<int>(m, 0));
    auto isOut = [&] (int y, int x) -> bool {
        return (y<0) || (y>=n) || (x<0) || (x>=m);
    };
    auto isTop = [&](int y, int x) -> bool {
        bool ret = true;
        for(int i=0; i<8; ++i) {
            int ny = y+dy[i], nx=x+dx[i];
            if(!isOut(ny, nx) && board[y][x] < board[ny][nx])
                ret = false;
        }
        return ret;
    };
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> board[i][j];
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
        if(discovered[i][j]) continue;
        queue<pii> q;
        q.push({i, j});
        discovered[i][j] = true;
        bool valid = isTop(i, j);
        while(!q.empty()) {
            int y = q.front().first, x = q.front().second; q.pop();
            for(int i=0; i<8; ++i) {
                int ny = y+dy[i], nx=x+dx[i];
                if(!isOut(ny, nx) && !discovered[ny][nx] && board[ny][nx] == board[y][x]) {
                    valid &= isTop(ny, nx);
                    discovered[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
        if(valid) ++ans;
    }
    cout << ans << '\n';
}
/*
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int dy[] = {0, 0, 1, 1, 1, -1, -1, -1}, dx[] = {1, -1, 1, -1, 0, 1, -1, 0};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    auto isOut = [&](int y, int x) -> bool {
        return (y < 0) || (y >= n) || (x < 0) || (x >= m);
    };
    vector<vector<int>> board(n, vector<int>(m)), visited(n, vector<int>(m, 0)), isBigger(n, vector<int>(m, 0));
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> board[i][j];
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
        for(int d=0; d<8; ++d) {
            int ny=i+dy[d], nx=j+dx[d];
            if(isOut(ny, nx)) continue;
            if(board[ny][nx] > board[i][j]) isBigger[i][j]=true;
        }
    int ans = 0;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) {
        if(visited[i][j]) continue;
        queue<pii> q;
        q.push({i, j});
        visited[i][j] = true;
        bool isTop = (!isBigger[i][j]) && board[i][j];
        while(!q.empty()) {
            int y=q.front().first, x=q.front().second; q.pop();
            for(int d=0; d<8; ++d) {
                int ny=y+dy[d], nx=x+dx[d];
                if(isOut(ny, nx)) continue;
                if(board[ny][nx] == board[y][x] && !visited[ny][nx]) {
                    isTop &= (!isBigger[i][j]);
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
        if(isTop)
            ans++;
    }
    cout << ans << '\n';
}
*/
