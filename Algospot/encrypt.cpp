#include<iostream>
#include<string>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while(t--){
		string str;
		cin>>str;
		string ans;
		for(int i=0; i<str.size(); i+=2)
			ans+=str[i];
		for(int i=1; i<str.size(); i+=2)
			ans+=str[i];
		cout<<ans<<'\n';
	}
}