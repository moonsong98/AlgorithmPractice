#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string str[8];
	int ans=0;
	for(int i=0; i<8; ++i) cin >>str[i];
	for(int i=0; i<8; ++i) for(int j=0; j<8; ++j) if((i+j)%2==0 && str[i][j]=='F') ++ans;
	cout << ans << '\n';
}