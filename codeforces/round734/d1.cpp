#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n, m, kh, kv;
		cin>>n>>m>>kh;
		kv=n*m/2-kh;
		if(n&1){
			kh-=m/2;
			if(kh<0){
				cout<<"NO"<<endl;
				continue;
			} 
		}
		if(m&1){
			kv-=n/2;
			if(kv<0){
				cout<<"NO"<<endl;
				continue;
			}
		}
		if(kh&1||kv&1){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
	}
}