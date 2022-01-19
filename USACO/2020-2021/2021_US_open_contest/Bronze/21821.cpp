#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> names;

int getIndex(string& name) {
	for(int i=0; i<names.size(); ++i)
		if(name==names[i]) return i;
}

int main(void) {
	int k, n; cin >> k >> n;
	names=vector<string>(n);
	vector<vector<int>> ans(n,vector<int>(n, -1));
	vector<vector<bool>> cmpName(n, vector<bool>(n, false)); // cmpName[i][j] == true => names[i] < names[j];
	for(int i=0; i<n; ++i) ans[i][i]=2;
	for(int i=0; i<n; ++i) cin >> names[i];
	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			if(names[i]<names[j]) cmpName[i][j]=true;
			else cmpName[j][i]=true;
		}
	}
	for(int i=0; i<k; ++i) {
		vector<int> seq;
		for(int j=0; j<n; ++j) {
			string s; cin >> s; seq.push_back(getIndex(s));
		}
		for(int j=0; j+1<n; ++j) {
			if(!cmpName[seq[j]][seq[j+1]]) {
				for(int k=j+1; k<n; ++k) {
					for(int l=0; l<=j; ++l) {
						ans[seq[l]][seq[k]]=0;
						ans[seq[k]][seq[l]]=1;
					}
				}
			}
		}
	}
	
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(ans[i][j]==1) {
				for(int k=0; k<n; ++k) {
					if(ans[i][k]==0 && ans[k][j]==-1) {
						ans[k][j]=1;
						ans[j][k]=0;
					}
					else if(ans[j][k]==1 && ans[i][k]==-1) {
						ans[i][k]=1;
						ans[k][i]=0;
					}
				}
			}
		}
	}
	
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(ans[i][j]==-1) cout << '?';
			else if(ans[i][j]==2) cout << 'B';
			else  cout << ans[i][j];
		}
		cout << '\n';
	}
}