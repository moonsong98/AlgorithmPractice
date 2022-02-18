#include<iostream>
#include<map>

using namespace std;

int dy[]={1, 0, -1, 0};
int dx[]={0, 1, 0, -1};

const int INF=987654321;

typedef struct {
	int y;
	int x;
} point;

bool operator < (const point& a, const point& b) {
	if(a.y!=b.y) return a.y<b.y;
	return a.x < b.x;
}

int main(void) {
	map<point, int> p2t;
	map<char, int> d2i={{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
	int N; cin >> N;
	int ans=INF;
	int y=0, x=0, t=0;
	for(int i=0; i<N; ++i) {
		char dir;
		int amount;
		cin >> dir >> amount;
		int d=d2i[dir];
		for(int j=1; j<=amount; ++j) {
			++t;
			y+=dy[d];
			x+=dx[d];
			if(!(y==0&&x==0) && p2t[{y, x}]==0) p2t[{y, x}]=t;
			else {
				ans=min(ans, t-p2t[{y, x}]);
				p2t[{y, x}]=t;
			}
		}
	}
	cout << (ans==INF?-1:ans) << '\n';
}