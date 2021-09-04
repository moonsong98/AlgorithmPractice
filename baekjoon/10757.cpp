#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
	string a, b;
	int ans[100*100+11]={0,};
	int size;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	size=max(a.size(), b.size());
	
	for(int i=0; i<size; ++i){
		if(a.size()<=i) ans[i]=b[i]-'0';
		else if(b.size()<=i) ans[i]=a[i]-'0';
		else ans[i]=a[i]-'0'+b[i]-'0';
	}
	
	for(int i=0; i<=size; ++i)
		if(ans[i]>=10) {
			ans[i+1] += ans[i]/10;
			ans[i]%=10;
		}
	
	for(int i=(ans[size]==0?size-1:size); i>=0; --i)
		cout<<ans[i];
}