#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int main(void) {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    queue<pair<int,int>> q;
    vector<bool> visited(f+1, false);
    q.push({s, 0});
    visited[s]=true;
    while(!q.empty()) {
        int here=q.front().first, num=q.front().second; q.pop();
        if(here==g) {
            cout << num << '\n';
            return 0;
        }
        if(here-d>0&&!visited[here-d]) {
            visited[here-d]=true;
            q.push({here-d, num+1});
        } 
        if(here+u<=f&&!visited[here+u]) {
            visited[here+u]=true;
            q.push({here+u, num+1});
        } 
    }
    cout << "use the stairs" << '\n';
}
