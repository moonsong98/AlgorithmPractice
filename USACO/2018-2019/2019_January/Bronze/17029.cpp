#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void) {
	int n; cin >> n;
	vector<string> names(n);
	vector<vector<string>> characteristics(n);
	for(int i=0; i<n; ++i){
		cin >> names[i];
		int m; cin >> m;
		for(int j=0; j<m; ++j) {
			string c; cin >> c;
			characteristics[i].push_back(c);
		}
	}
	int ans=0;
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			int cnt=0;
			for(int k=0; k<characteristics[i].size(); ++k) {
				for(int l=0; l<characteristics[j].size(); ++l) {
					if(characteristics[i][k]==characteristics[j][l]) ++cnt;
				}
			}
			ans=max(ans,cnt+1);
		}
	}
	cout << ans << '\n';
}