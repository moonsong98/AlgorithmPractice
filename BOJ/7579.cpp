#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n, m;
	int costSum=0;
	int dp[100*100+11]={0,}; // cost[i] 에서 얻을 수 있는 최대 Memory;
	cin >> n >> m;
	
	vector<int> memory(n, 0), cost(n,0);
	
	for(int i=0; i<n; ++i) cin >> memory[i];
	for(int i=0; i<n; ++i) {
		cin >> cost[i];
		costSum+=cost[i];
	}
	
	for(int i=0; i<n; ++i)
		for(int j=costSum; j>=cost[i]; --j)
			dp[j]=max(dp[j], dp[j-cost[i]]+memory[i]);
	
	for(int i=0; i<=costSum; ++i)
		if(dp[i]>=m){
			cout << i <<'\n';
			return 0;
		}
}


/* wrong code
#include<iostream>
#include<map>
#include<utility>
#include<vector>

using namespace std;

const int INF=100*100+11;

map<pair<int,int>, int> M;
vector<int> mem, cost;
int n, m;

int dp(int pos, int memory){
	if(pos==n) return memory >= m ? 0: INF;
	map<pair<int,int>, int>::iterator it=M.find({pos, memory});
	if(it!=M.end()) return it->second;
	return M[{pos, memory}]=min(dp(pos+1, memory), dp(pos+1, memory+mem[pos])+cost[pos]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	
	mem=vector<int>(n,0);
	cost=vector<int>(n,0);
	
	for(int i=0; i<n; ++i) cin>>mem[i];
	for(int i=0; i<n; ++i) cin>>cost[i];
	
	cout << dp(0, 0) <<'\n';
}

/*
dp(pos, m) = min(dp(pos+1, m), dp(pos+1, m-mem[pos])+cost[pos];
*/
