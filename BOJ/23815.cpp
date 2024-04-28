#include<iostream>

using namespace std;

int calc(int a, char op, int b) {
	switch(op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

int main(void) {
	int n; cin >> n;
	int dp[2]={1,-1}; //dp[0]: used skip dp[1]: not used yet
	for(int i=0; i<2; ++i) {
		char op; int b;
		cin >> op >> b;
		if(dp[1]<=calc(1,op,b)) dp[1]=calc(1,op,b);
	}
	for(int i=0; i+1<n; ++i) {
		int tmp[2]={-1,-1}; 
		if(dp[1]>0) tmp[0]=dp[1];
		char op; int b;
		cin >> op >> b;
		tmp[0]=max(tmp[0], calc(dp[0],op,b));	
		if(dp[1]>0)tmp[1]=calc(dp[1],op,b);
		cin >> op >> b;
		tmp[0]=max(tmp[0], calc(dp[0],op,b));	
		if(dp[1]>0)tmp[1]=max(tmp[1], calc(dp[1],op,b));	
		if(tmp[0]<=0 && tmp[1]<=0) {
			cout << "ddong game" << '\n';
			return 0;	
		}
		dp[0]=tmp[0], dp[1]=tmp[1];
	} 
	cout << max(dp[0], dp[1]) << '\n'; 
}
