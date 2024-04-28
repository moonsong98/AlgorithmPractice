#include<iostream>

using namespace std;

long long values[81];

void preCalc() {
	values[1]=values[2]=1;
	for(int i=3; i<=80; ++i) values[i]=values[i-1]+values[i-2];
}

int main(void) {
	preCalc();
	int n;
	cin >> n;
	if(n==1) cout << 4 << '\n';
	else cout << 2*(values[n]*2+values[n-1]) << '\n';
}