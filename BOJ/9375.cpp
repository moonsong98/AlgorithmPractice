#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int clothes[31];
vector<string> kind; 

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--){
		memset(clothes,0,sizeof(clothes));
		kind=vector<string>();
		int n;
		cin>>n;
		for(int i=0; i<n; ++i){
			string a, b;
			cin >> a >> b;
			int j=0;
			for(; j<kind.size(); ++j)
				if(kind[j]==b) {
					clothes[j]++;
					break;
				}
			if(j==kind.size()){
				kind.push_back(b);
				clothes[j]++;
			}
		}
		int ans=1;
		for(int i=0; i<kind.size(); ++i)
			ans*=(clothes[i]+1);
		cout<<ans-1<<'\n';
	}
}