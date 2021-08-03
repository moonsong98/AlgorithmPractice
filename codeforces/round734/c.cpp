#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> cache[5];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int t;
	string str;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0; i<5; ++i) 
			cache[i]=vector<int>(n,0);
		for(int i=0; i<n; ++i){
			cin>>str;
			int numA[5]={0,};
			for(int j=0; j<str.size(); ++j)
				numA[str[j]-'a']++;
			for(int j=0; j<5; ++j)
				cache[j][i]=numA[j]*2-str.size();
		}
		
		int ret=0;
		for(int i=0;i<5;++i){
			int ans=0;
			int cnt=0;
			sort(cache[i].begin(), cache[i].end());
			reverse(cache[i].begin(), cache[i].end());
			for(int j=0; j<n; ++j){
				if(ans+cache[i][j]>0){
					ans+=cache[i][j];
					cnt++;
				}
			}
			ret=max(ret,cnt);
		}
		cout<<ret<<endl;
	}
}
