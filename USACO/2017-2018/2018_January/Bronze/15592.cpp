#include<iostream>

using namespace std;

int main(void) {
	int cord[2][2][2];
	for(int i=0; i<2; ++i)
		cin >> cord[i][0][0] >> cord[i][1][0] >> cord[i][0][1] >> cord[i][1][1];
	int area=(cord[0][0][1]-cord[0][0][0])*(cord[0][1][1]-cord[0][1][0]);
	if(cord[0][0][1]==min(cord[1][0][1],cord[0][0][1]) && cord[0][0][0]==max(cord[1][0][0], cord[0][0][0]) &&
	  (cord[0][1][1]==min(cord[1][1][1],cord[0][1][1]) || cord[0][1][0]==max(cord[1][1][0], cord[0][1][0]))) {
		int h=max(min(cord[1][1][1],cord[0][1][1])-max(cord[1][1][0],cord[0][1][0]),0);
		cout << area-(cord[0][0][1]-cord[0][0][0])*h;
	}
	else if(cord[0][1][1]==min(cord[1][1][1],cord[0][1][1]) && cord[0][1][0]==max(cord[1][1][0], cord[0][1][0]) &&
		   (cord[0][0][1]==min(cord[1][0][1],cord[0][0][1]) || cord[0][0][0]==max(cord[1][0][0], cord[0][0][0]))) {
		int v=max(min(cord[1][0][1],cord[0][0][1])-max(cord[1][0][0],cord[0][0][0]),0);
		cout << area-(cord[0][1][1]-cord[0][1][0])*v;
	}
	else cout << area << '\n';
}