#include<bits/stdc++.h>
using namespace std;

/**
 * Tree의 Node 중 Root로 뒀을 때, Path Length가 짝수인 Leaf Node의 최대 개수 구하기
 * 1) 한번 Leaf Node는 영원한 Leaf Node
 * 2) Connected Graph인가?
 * */

typedef struct st {
    int odd, even;
} Info;
typedef pair<int,int> P;

vector<Info> info;
vector<vector<int>> adj;

bool dfs(int u, int parent) {
    info[u] = {0,0};
    if(adj[u].size() == 1) return true;
    for(int v: adj[u]) {
        if(v == parent) continue;
        bool isLeaf = dfs(v, u);
        if(isLeaf) info[u].odd += 1;
        info[u].odd += info[v].even;
        info[u].even += info[v].odd;
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    adj = vector<vector<int>>(N+1);
    info = vector<Info>(N+1);
    for(int i=0; i+1<N; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root = -1;
    for(int i = 1; i <= N; ++i)
        if(adj[i].size() > 1) {
            root = i;
            break;
        }
    if(root == -1) {
        if(N == 1) cout << 1 << '\n';
        else if(N == 2) cout << 0 << '\n';
        return 0;
    }
    dfs(root, -1);
    bool onlyLeaf = true;
    for(int v: adj[root]) 
        if(adj[v].size() > 1)
            onlyLeaf = false;
    if(info[root].even > info[root].odd)
        cout << info[root].even << '\n';
    else {
        if(onlyLeaf) cout << max(info[root].even , info[root].odd-1) << '\n';
        else cout << info[root].even << '\n';
    }
}
