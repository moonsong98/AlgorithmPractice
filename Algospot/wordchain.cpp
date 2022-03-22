#include<bits/stdc++.h>
#define sz(x) (int)x.size()

using namespace std;

vector<vector<int>> adj;
vector<int> in, out;
vector<int> ans;

void dfs(int u) {
	for(int v=0; v<26; ++v)
		while(adj[u][v]) {
			--adj[u][v];
			dfs(v);
		}
	ans.push_back(u);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		ans.clear();
		adj=vector<vector<int>> (26, vector<int>(26, 0));
		in=vector<int>(26,0);
		out=vector<int>(26,0);
		vector<vector<vector<string>>> words(26,vector<vector<string>>(26));
		int n;
		cin >> n;
		for(int i=0; i<n; ++i) {
			string str;
			cin >> str;
			int u=str[0]-'a', v=str.back()-'a';
			adj[u][v]++;
			out[u]++;
			in[v]++;
			words[u][v].push_back(str);
		}
		int cnt1=0,cntm1=0, si=-1;
		bool isPossible=true;
		for(int i=0; i<26; ++i) {
			if(out[i]-in[i]>=2||in[i]-out[i]>=2) {
				isPossible=false;
				break;
			}
			if(out[i]-in[i]==1) {
				++cnt1;
				si=i;
			}
			if(out[i]-in[i]==-1) ++cntm1;
		}
		isPossible=(cnt1==0&&cntm1==0)||(cnt1==1&&cntm1==1);
		if(!isPossible) {
			cout << "IMPOSSIBLE" << '\n';
			continue;
		} 
		if(si!=-1)
			dfs(si);
		else 
			for(int i=0; i<26; ++i)
				if(out[i]) {
					dfs(i);
					break;
				}
		reverse(ans.begin(), ans.end());
		if(ans.size()!=n+1) {
			cout << "IMPOSSIBLE" << '\n';
			continue;
		}
		for(int i=0; i+1<sz(ans); ++i) {
			string str=words[ans[i]][ans[i+1]].back();
			words[ans[i]][ans[i+1]].pop_back();
			cout << str << ' ';
		}
		cout << '\n';
	}
}