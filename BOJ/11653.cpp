#include<iostream>

using namespace std;

bool prime[100*1000*1000+11];

int main(void) {
	int n;
	cin >> n;
	
	for(int i=2; i<=n; ++i) prime[i]=true;
	
	for(int i=2; i*i<=n; ++i){
		if(!prime[i]) continue;
		for(int j=i*2; j<=n; j+=i) prime[i]=false;
	}
	
	int p=2;
	
	while(n>1){
		for(;(n%p||!prime[p]);++p){
			cout << p;
		};
		cout<<p<<'\n';
		n/=p;
	}
}