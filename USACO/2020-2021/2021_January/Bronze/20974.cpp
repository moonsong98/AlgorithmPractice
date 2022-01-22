#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n; cin >> n;
	int numEven=0, numOdd=0;
	for(int i=0; i<n; ++i) {
		int a; cin >> a;
		a%2?++numOdd:++numEven;
	}
	while(numOdd>numEven) {
		numOdd-=2;
		++numEven;
	}
	if(numEven>numOdd+1) numEven=numOdd+1;
	cout << numEven+numOdd << '\n';
}