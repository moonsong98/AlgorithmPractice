#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

vector<int> cache;
int pow3[15], n;

void init() {
	pow3[0]=1;
	for(int i=1; i<=14; ++i) pow3[i]=pow3[i-1]*3;
}

int getIdx(string str) {
	int ret=0;
	for(int i=0; i<n; ++i)
		ret+=(str[n-i-1]-'A'+1)*pow3[i];
	return ret;
}

void calc(int cnt[]) {
	string str;
	for(int i=0; i<3; ++i)
		for(int j=0; j<cnt[i]; ++j)
			str+='A'+i;
	queue<pair<string, int>> q;
	q.push({str, 0});
	cache[getIdx(str)]=0;
	while(!q.empty()) {
		string s=q.front().first;
		int num=q.front().second;
		q.pop();
		for(int i=2; i<=n; ++i) {
			string tmp=s;
			reverse(tmp.begin(), tmp.begin()+i);
			int idx=getIdx(tmp);
			if(cache[idx]==-1) {
				cache[idx]=num+1;
				q.push({tmp, num+1});
			}
		}
	}
}

int main(void) {
	init();
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int q;
	cin >> n >> q;
	cache=vector<int>(pow3[n+1], -1);
	for(int i=0; i<q; ++i) {
		string str; cin >> str;
		int cnt[3]={0, 0, 0};
		for(char ch: str) cnt[ch-'A']++;
		if(cache[getIdx(str)]==-1)
			calc(cnt);
		cout << cache[getIdx(str)] << '\n';
	}
}