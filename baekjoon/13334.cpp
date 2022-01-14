#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int main(void) {
    int n, d, ans=0; cin >> n;
    vector<pair<int,int>> posList;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<n; ++i) {
        int a, b; cin >> a >> b;
        a>b?posList.push_back({a,b}) : posList.push_back({b,a});
    }
    sort(posList.begin(),posList.end());
    cin >> d;

    for(int i=0; i<n; ++i) {
        pair<int,int> p = posList[i];
        if(p.first-p.second <= d) {
            while(!pq.empty() && p.first - pq.top() > d) pq.pop();
            pq.push(p.second);
            ans=max(ans, int(pq.size()));
        }
    }
    cout << ans << '\n';
}
