#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--){
		priority_queue<int,vector<int>,greater<int>> q;
		int n;
		cin>>n;
		for(int i=0; i<n; ++i){
			int a;
			cin>>a;
			q.push(a);
		}
		
		int ans=0;
		while(q.size()>1){
			int a=q.top();q.pop();
			int b=q.top();q.pop();
			ans+=a+b;
			q.push(a+b);
		}
		cout<<ans<<'\n';
	}
}