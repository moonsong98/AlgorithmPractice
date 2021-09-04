#include<iostream>

using namespace std;

int main(void) {
	int n;
	cin>>n;
	
	int ans=0;
	for(int i=1; i<=1000*1000; ++i){
		int sum=0;
		int c=i;
		while(c>0){
			sum+=c%10;
			c/=10;
		}
		sum+=i;
		if(n==sum){
			ans=i;
			break;
		}
	}
	cout<<ans<<'\n';
}