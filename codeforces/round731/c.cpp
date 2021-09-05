#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int k,n,m;
		int a[3*100+11], b[3*100+11];
		vector<int> ans;
		cin>>k>>n>>m;
		for(int i=0; i<n; ++i)
			cin >>a[i];
		for(int i=0; i<m; ++i)
			cin >>b[i];
		int idxA=0, idxB=0;
		bool finished=false;
		while(idxA<n||idxB<m){
			if(idxA==n){
				if(b[idxB]==0) ++k;
				else if(b[idxB]>k){
					finished=true;
					break;
				}
				ans.push_back(b[idxB++]);
			}
			else if(idxB==m){
				if(a[idxA]==0) ++k;
				else if(a[idxA]>k){
					finished=true;
					break;
				}
				ans.push_back(a[idxA++]);
			}
			else {
				if(a[idxA]<b[idxB]){
					if(a[idxA]==0) ++k;
					else if(a[idxA]>k){
						finished=true;
						break;
					}
					ans.push_back(a[idxA++]);
				}
				else {
					if(b[idxB]==0) ++k;
					else if(b[idxB]>k){
						finished=true;
						break;
					}
					ans.push_back(b[idxB++]);
				}
			}
		}
		if(finished) { 
			cout <<"-1"<<'\n';
			continue;
		}
		for(int num:ans)
			cout<<num<<' ';
		cout<<'\n';
		
	}
}