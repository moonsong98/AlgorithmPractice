#include<iostream>
#include<vector>

using namespace std;

typedef struct {
	int y;
	int x;
} point;

const int MAX=1987654321;
const int MIN=-1;

int main(void) {
	int N;
	cin >> N;
	int xm, xM, ym, yM;
	int xmi, xMi, ymi, yMi;
	ym=xm=MAX;
	yM=xM=MIN;
	vector<point> points;
	for(int i=0; i<N; ++i) {
		int a, b; cin >> a >> b;
		points.push_back({a,b});
		if(a>yM) {
			yM=a;
			yMi=i;
		}
		if(a<ym) {
			ym=a;
			ymi=i;
		}
		if(b>xM) {
			xM=b;
			xMi=i;
		}
		if(b<xm) {
			xm=b;
			xmi=i;
		}
	}
	int ans=MAX;
	ym=xm=MAX;
	yM=xM=MIN;
	for(int i=0; i<N; ++i) {
		if(i==xmi) continue;
		ym=min(ym,points[i].y);
		xm=min(xm,points[i].x);
		yM=max(yM,points[i].y);
		xM=max(xM,points[i].x);
	}
	ans=min(ans,(yM-ym)*(xM-xm));
	ym=xm=MAX;
	yM=xM=MIN;
	for(int i=0; i<N; ++i) {
		if(i==xMi) continue;
		ym=min(ym,points[i].y);
		xm=min(xm,points[i].x);
		yM=max(yM,points[i].y);
		xM=max(xM,points[i].x);
	}
	ans=min(ans,(yM-ym)*(xM-xm));
	ym=xm=MAX;
	yM=xM=MIN;
	for(int i=0; i<N; ++i) {
		if(i==ymi) continue;
		ym=min(ym,points[i].y);
		xm=min(xm,points[i].x);
		yM=max(yM,points[i].y);
		xM=max(xM,points[i].x);
	}
	ans=min(ans,(yM-ym)*(xM-xm));
	ym=xm=MAX;
	yM=xM=MIN;
	for(int i=0; i<N; ++i) {
		if(i==yMi) continue;
		ym=min(ym,points[i].y);
		xm=min(xm,points[i].x);
		yM=max(yM,points[i].y);
		xM=max(xM,points[i].x);
	}
	ans=min(ans,(yM-ym)*(xM-xm));
	cout << ans << '\n';
}