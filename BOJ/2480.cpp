#include<bits/stdc++.h>

using namespace std;

int main(void){
	int a, b, c;
	cin >> a >> b >> c;
	if(a==b&&b==c) cout << 10000+a*1000;
	else if(a==b) cout << 1000+a*100;
	else if(c==b) cout << 1000+b*100;
	else if(a==c) cout << 1000+a*100;
	else cout << 100*max({a,b,c});
}