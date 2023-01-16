#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int main(void) {
    Point A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    int cp=(-A.x+B.x)*(C.y-B.y)-(C.x-B.x)*(-A.y+B.y);
    if(cp>0) cout << 1 << '\n';
    if(cp==0) cout << 0 << '\n';
    if(cp<0) cout << -1 << '\n';
}
