#include<iostream>
#include<string>

using namespace std;


int main(void) {
	int num[6]={1,};
	int ans=0;
	for(int i=1; i<6; ++i) num[i]=16*num[i-1];
	string x;
	cin >> x;
	x=string(x.rbegin(), x.rend());
	for(int i=0; i<x.size(); ++i) {
		if('A'<=x[i] && x[i] <='F') ans+=(x[i]-'A'+10)*num[i];
		else ans+=(x[i]-'0')*num[i];
	}
	cout << ans << '\n';
}