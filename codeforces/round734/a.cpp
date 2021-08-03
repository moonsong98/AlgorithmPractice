#include<iostream>

using namespace std;

int main(void){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a=n/3;
		int b=a;
		if(n%3==1)a+=1;
		if(n%3==2)b+=1;
		cout<<a<<' '<<b<<endl;
	}
}