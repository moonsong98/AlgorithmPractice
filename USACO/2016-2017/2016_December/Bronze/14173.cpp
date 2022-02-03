#include<iostream>

using namespace std;

const int MAX=987654321;
const int MIN=-1;

int main(void) {
	int maxX, maxY, minX, minY;
	maxX = maxY = MIN;
	minX = minY = MAX;
	
	for(int i=0; i<2; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		maxX=max(maxX, c);
		maxY=max(maxY, d);
		minX=min(minX, a);
		minY=min(minY, b);
	}
	
	cout << max((maxX-minX)*(maxX-minX), (maxY-minY)*(maxY-minY)) << '\n';
}