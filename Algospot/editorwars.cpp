#include<iostream>
#include<vector>

using namespace std;

void swap(int& u, int& v){
	int t=u;
	u=v;
	v=u;
}

struct DisjointSet{
	int n;	
	vector<int> rank, parent, enemy, size;
	DisjointSet(int _n):n(_n),rank(_n, 1), enemy(_n,-1), size(_n,1), parent(_n){
		for(int i=0; i<_n; ++i) parent[i]=i;
	}
	int find(int u){
		if(parent[u]==u) return u;
		parent[u]=find(parent[u]);
	}
	int merge(int u, int v){
		if(u==-1||v==-1) max(u,v);
		u=find(u), v=find(v);
		if(u==v) return u;
		if(rank[u]>rank[v]) swap(u,v);
		parent[u]=v;
		if(rank[u]==rank[v]) rank[v]+=1;
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
		if(u==enemy[v]||v==enemy[u]) return true;
		int a=merge(u,v);
		int b=merge(enemy[u],enemy[v]);
		enemy[b]=a;
		if(a!=-1) enemy[b]=a;
		return false;
	}
	void debug() {
		cout << n;
		for(int i=0; i<n; ++i)
			cout<<parent[i];
		cout<<endl;
	}
};

void solve() {
	int n, m;	
	cin>>n>>m;
	DisjointSet buf(n);
	int con=-1, ret=0;
	for(int i=0; i<m; ++i){
		string str;
		int a, b;
		cin>>str>>a>>b;
		if(con^-1) continue;
		if(str.compare(string("ACK"))?buf.dis(a,b):buf.ack(a,b)) con=i;
	}
	buf.debug();
	if(con^-1) cout<<"CONTRADICTION AT "<<con<<endl;
	else {
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
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;	
	while(t--) solve();
}