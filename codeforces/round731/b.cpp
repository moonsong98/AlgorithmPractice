#include<iostream>
#include<string>

using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--){
		int count[26]={0,};
		string str;
		cin>>str;
		bool appeared=false;
		bool finished=false;
		for(int i=0; i<str.size(); ++i){
			if(str[i]=='a') appeared=true;
			else if(i>0) {
				if(!appeared && str[i]>str[i-1]){
					cout<<"NO"<<'\n';
					finished=true;
					break;
				}
				if(appeared && str[i]<str[i-1]){
					cout<<"NO"<<'\n';
					finished=true;
					break;
				}
			}
			count[str[i]-'a']++;
		}
		if(finished) continue;
		for(int i=0; i<str.size(); ++i)
			if(count[i]!=1){
				cout<<"NO"<<'\n';
				finished=true;
				break;
			}
		if(!finished)
			cout<<"YES"<<'\n';
	}
}