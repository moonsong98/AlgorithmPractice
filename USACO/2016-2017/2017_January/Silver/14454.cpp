#include<bits/stdc++.h>
using namespace std;

int main(void) {
	string str;
	cin >> str;
	long long size=(long long)str.size(),N, M=size;
	cin >> N;
	while(M<N) M<<=1;
	while(N>size) {
		if(N>(M>>1)){
			if(N-(M>>1)==1) N=M>>1;
			else N=N-(M>>1)-1;
		} 
		M>>=1;
	}
	cout << str[N-1] << '\n';
}