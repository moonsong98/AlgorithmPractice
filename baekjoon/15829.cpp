#include<iostream>
#include<string>

using namespace std;

long long p[51];
const long long MOD=1234567891ll;

void preMul() {
	p[0]=1;
	for(int i=1; i<=50; ++i) 
		p[i]=((31%MOD)*(p[i-1]%MOD))%MOD;
}

int main(void) {
	int n;
	string str;
	long long h=0;
	cin >> n;
	cin >> str;
	
	preMul();
	for(int i=0; i<n; ++i) {
		long long a=str[i]-'a'+1;
		h= ((h%MOD)+((a*(p[i]))%MOD))%MOD;
	}
	cout << h << '\n';
}
