#include<bits/stdc++.h>
#define sz(x) (long long)x.size()
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

typedef struct Point{
    ll x;
    ll y;
}Point;

typedef struct Line{
    Point p1;
    Point p2;
    ll w;
}Line;

int ccw(Point p1, Point p2, Point p3){
    ll a=p1.x*p2.y+p2.x*p3.y+p3.x*p1.y;
    ll b=p1.y*p2.x+p2.y*p3.x+p3.y*p1.x;
    if(a-b<0) return 1;
    else return -1;

    /*
    ll cp = (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);
    if (cp < 0)
        return 1;
    else if (cp < 0)
        return -1;
    else
        return 0;
        */
}

int comparator(Point left, Point right){
    if(left.x == right.x)
        return (left.y <= right.y);
    return (left.x <= right.x);
}

void swap(Point* p1, Point* p2){
    Point temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int LineIntersection(Line l1, Line l2){
    int l1_l2 = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
    int l2_l1 = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);
    return (l1_l2 <= 0) && (l2_l1 <= 0);
}

int N;
vector<Line> v;
vector<ll> numIntersected;
bool cmp(const pii& a, const pii& b) {
    if(a.first==b.first) 
        return numIntersected[a.second] < numIntersected[b.second];
    return a.first<b.first;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    Line l1, l2;
    cin >> l1.p1.x >> l1.p1.y >> l1.p2.x >> l1.p2.y;
    cin >> l2.p1.x >> l2.p1.y >> l2.p2.x >> l2.p2.y;
    cout << LineIntersection(l1, l2) << '\n';
    /*
    cin >> N;
    for(int i=0; i<N; ++i) {
        Line l;
        cin >> l.p1.x >> l.p1.y >> l.p2.x >> l.p2.y >> l.w;
        v.push_back(l);
    }
    vector<vector<int>> adj(N);
    for(int i=0; i<N; ++i) 
        for(int j=0; j<N; ++j) {
            if(i==j) continue;
            if(LineIntersection(v[i],v[j])) 
                adj[i].push_back(j);
        }
    ll ans=0;
    numIntersected=vector<ll>(N);
    vector<bool> removed(N, false);
    for(int i=0; i<N; ++i) numIntersected[i]=sz(adj[i]);
    for(int i=0; i<N; ++i) {
        vector<pii> cand;
        for(int i=0; i<N; ++i)
            if(removed[i]==false)
                cand.push_back({v[i].w*(numIntersected[i]+1), i});
        sort(cand.begin(), cand.end(), cmp);
        removed[cand[0].second]=true;
        ans+=cand[0].first;
        for(int v: adj[cand[0].second]) 
            numIntersected[v]--;
    }
    cout << ans << '\n';
    */
}

