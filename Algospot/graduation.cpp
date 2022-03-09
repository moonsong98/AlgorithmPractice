#include<iostream>
#include<vector>

using namespace std;

const int INF=1e9+7;
int N, K, M, L;
vector<int> prerequisite, classes;

int calc(int semester, int taken) {
	if(semester>M) return INF;
	if(__builtin_popcount(taken)>=K) return 0;
	int canTake=classes[semester]&(~taken);
	int ans=INF;
	for(int c=canTake; c; c=canTake&(c-1)){
		if(__builtin_popcount(c)>L) continue;
		int p=0;
		for(int i=0; i<N; ++i)
			if(c&(1<<i))
				p|=prerequisite[i];
		if((p&taken)!=p) continue;
		ans=min(ans, 1+calc(semester+1, taken|c));
	}
	ans=min(ans, calc(semester+1, taken));
	return ans;
}

void solve() {
	cin >> N >> K >> M >> L;
	prerequisite=vector<int>(N, 0);	
	classes=vector<int>(M, 0);
	for(int i=0; i<N; ++i) {
		int n;
		cin >> n;
		for(int j=0; j<n; ++j) {
			int a;
			cin >> a;
			prerequisite[i] |= (1<<a);
		}
	}
	for(int i=0; i<M; ++i) {
		int n;
		cin >> n;
		for(int j=0; j<n; ++j) {
			int a;
			cin >> a; 
			classes[i] |= (1<<a);
		}
	}
	
	int ans=calc(0,0);	
	if(ans==INF) cout << "IMPOSSIBLE" << '\n';
	else cout << ans << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}