#include<iostream>
#include<string>

using namespace std;

int main(void){
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int numA[26]={0,};
		int ret=0;
		int ones=0;
		for(int i=0; i<str.size();++i)
			numA[str[i]-'a']++;
		for(int i=0;i<26;++i){
			if(numA[i]>=2)ret+=1;
			if(numA[i]==1)ones+=1;
		}
		cout<<ret+ones/2<<endl;
	}
}