#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(void) {
	int n; cin >> n;
	map<string, int> m;
	for(int i=0; i<n; ++i) {
		int k; cin >> k;
		for(int j=0; j<k; ++j) {
			string str; cin >> str;
			m[str]|=(1<<i);
		}
	}
	bool ans=true;
	for(auto el1: m) for(auto el2: m) {
		int n1=el1.second, n2=el2.second;
		if(n1==(n1|n2) || n2==(n1|n2) || (n1&n2)==0) continue;
		ans=false;
		break;
	}
	cout << (ans ? "yes" : "no") << '\n';
}
/*
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

typedef struct {
	int nodeNum;
	set<string> features;
} node;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<node> nodes(n);
	for(int i=0; i<n; ++i) {
		int k; cin >> k;
		nodes[i].nodeNum=i;
		while(k--) {
			string s; cin >> s;
			nodes[i].features.insert(s);
		}
	}
	
	auto cmp=[&](node a, node b) {
		return a.features.size() < b.features.size();
	};
	
	sort(nodes.begin(), nodes.end(), cmp);
	
	bool ans=true;
	while(true) {
		vector<vector<bool>> group(n, vector<bool>(n, false));
		bool done=true;
		for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j)
			for(string f1:nodes[i].features)
				for(string f2:nodes[j].features)
					if(f1==f2) {
						done=false;
						group[i][i]=group[i][j]=true;
					}
		if(done) break;
		while(true) {
			bool changed=false;
			for(int i=n-1; i>=0; --i) for(int j=i+1; j<n; ++j) for(int k=0; k<n; ++k) {
				if(group[i][j]&&group[i][k]&&group[j][k]) {
					group[j][k]=false;
					changed=true;
				}
			}
			if(!changed) break;
		}
		for(int i=0; i<n; ++i) {
			int cnt=0;
			for(int j=0; j<n; ++j)
				cnt+=group[j][i];
			if(cnt>1) {
				ans=false;
				break;
			}
		}
		if(!ans) break;
		for(int i=0; i<n; ++i) {
			if(group[i][i]==false) continue;
			vector<string> shouldBeDeleted;
			for(set<string>::iterator it=nodes[i].features.begin(); it!=nodes[i].features.end(); ++it) {
				bool allContains=true;
				for(int j=i+1; j<n; ++j) {
					if(group[i][j]==false) continue;
					if(nodes[j].features.count(*it)==0) {
						allContains=false;
						break;
					}
				}
				if(allContains) {
					shouldBeDeleted.push_back(*it);
					for(int j=i+1; j<n; ++j) {
						if(nodes[j].features.find(*it)!=nodes[j].features.end())
							nodes[j].features.erase(nodes[j].features.find(*it));
					}
				}
			}
			for(string str:shouldBeDeleted) {
				if(nodes[i].features.find(str)!=nodes[i].features.end())
					nodes[i].features.erase(nodes[i].features.find(str));
			}
		}
		sort(nodes.begin(), nodes.end(), cmp);
	}
	cout << (ans?"yes":"no") << '\n';
}
*/
