#include<iostream>

using namespace std;

int main(void) {
	int cords[3][2][2];
	for(int i=0; i<3; ++i)
		cin >> cords[i][0][0] >> cords[i][1][0] >> cords[i][0][1] >> cords[i][1][1]; // ith x or y left or right

	int ans=0;
	for(int i=0; i<2; ++i) {
		ans+=(cords[i][1][1]-cords[i][1][0])*(cords[i][0][1]-cords[i][0][0]);
		int v=max(min(cords[2][0][1],cords[i][0][1])-max(cords[2][0][0],cords[i][0][0]),0);
		int h=max(min(cords[2][1][1],cords[i][1][1])-max(cords[2][1][0],cords[i][1][0]),0);
		ans-=v*h;
	}
	cout << ans << '\n';
}