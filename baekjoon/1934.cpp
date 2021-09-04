#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		if(a>b){
			int t;
			t=a; a=b; b=t;
		}
		int c=a, d=b;
		while(b>0) {
			int r=a%b;
			a=b;b=r;
		}
		cout<<c*d/a<<'\n';
	}
}