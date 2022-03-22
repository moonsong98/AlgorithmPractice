#include<iostream>
#include<vector>

using namespace std;

void swap(int& u, int& v){
	int t=u;
	u=v;
	v=t;
}

struct DisjointSet{
	int n;	
	vector<int> rank, parent, enemy, size;
	DisjointSet(int _n):n(_n),rank(n, 1), enemy(n,-1), size(n,1), parent(n){
		for(int i=0; i<n; ++i) parent[i]=i;
	}
	int find(int u){
		if(parent[u]==u) return u;
		return parent[u]=find(parent[u]);
	}
	int merge(int u, int v){
		if(u==-1||v==-1) return max(u,v);
		u=find(u), v=find(v);
		if(u==v) return u;
		if(rank[u]>rank[v]) swap(u,v);
		parent[u]=v;
		if(rank[u]==rank[v]) rank[v]++;
		size[v]+=size[u];
		return v;
	}
	//true==contradiction
	bool dis(int u, int v){
		u=find(u),v=find(v);	
		if(u==v) return true;
		int a=merge(enemy[u],v);
		int b=merge(enemy[v],u);
		enemy[a]=b; enemy[b]=a;
		return false;
	}
	bool ack(int u, int v){
		u=find(u),v=find(v);
		if(enemy[u]==v) return true;
		int a=merge(u,v);
		int b=merge(enemy[u],enemy[v]);
		enemy[a]=b;
		if(b!=-1) enemy[b]=a;
		return false;
	}
};

void solve() {
	int n, m;	
	cin>>n>>m;
	DisjointSet buf(n);
	int ret=0, con=-1;
	for(int i=1; i<=m; ++i){
		string str;
		int a, b;
		cin >> str >> a >> b;
		if(con!=-1) continue;
		if(str=="ACK"?buf.ack(a,b):buf.dis(a,b)) con=i;
	}
	if(con!=-1) {
		cout<<"CONTRADICTION AT "<<con<<endl;
		return;
	}
	for(int i=0; i<n; ++i){
		//root of set
		if(buf.parent[i]==i){
			int enemy=buf.enemy[i];
			//only consider i > enemy to avoid duplicate cases
			if(enemy>i) continue;
			int mySize=buf.size[i];
			int enemySize=(enemy==-1?0:buf.size[enemy]);
			ret+=max(mySize,enemySize);
		}
	}	
	cout<<"MAX PARTY SIZE IS "<<ret<<endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;	
	while(t--) solve();
}