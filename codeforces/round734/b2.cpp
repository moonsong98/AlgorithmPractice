#include<iostream>
#include<vector>
#include<map>
#include<cstring>

using namespace std;

int ans[2*100*1001];
map<int,vector<int>> indices;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		memset(ans,0,sizeof(ans));
		indices.clear();
		int n,k;
		cin>>n>>k;
		int count=0;
		for(int i=0; i<n; ++i){
			int a;
			cin>>a;
			if(indices[a].size()<k){
				indices[a].push_back(i);
				count+=1;
			}
		}
		count-=count%k;	
		//cout<<"count: "<<count<<endl;
		for(map<int,vector<int>>::iterator it=indices.begin(); it!=indices.end(); ++it){
			vector<int> value=it->second;
		//	cout<<it->first<<' '<<it->second.size()<<endl;
			for(int i=0;i<value.size();++i){
				if(count==0) break;
				ans[value[i]]=count%k+1;
				--count;
			}
			if(count==0) break;
		}
		for(int i=0;i<n;++i)
			cout<<ans[i]<<' ';
		cout<<endl;
	}
}