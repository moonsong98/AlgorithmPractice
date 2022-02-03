#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

map<string,int> mapNameId;
int parent[200];
int depth[200];

int getDepth(int u) {
	if(depth[u]!=-1) return depth[u];
	if(parent[u]==-1) return depth[u]=0;
	return depth[u]=getDepth(parent[u])+1;
}

int main(void) {
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	int N, cntNode=1;
	string A, B;
	cin >> N >> A >> B;
	mapNameId[A]=cntNode++;
	mapNameId[B]=cntNode++;
	for(int i=0; i<N; ++i) {
		string A, B;
		cin >> A >> B;
		mapNameId[A]==0&&(mapNameId[A]=cntNode++);
		mapNameId[B]==0&&(mapNameId[B]=cntNode++);
		parent[mapNameId[B]]=mapNameId[A];
	}
	for(int i=1; i<cntNode; ++i) getDepth(i);
	int a=1, b=2, cnt=0;
	if(depth[a]>depth[b]) {
		int num=depth[a]-depth[b];
		for(int i=0; i<num; ++i) a=parent[a];
	}
	else if(depth[b]>depth[a]){
		int num=depth[b]-depth[a];
		for(int i=0; i<num; ++i) b=parent[b];
	}
	while(a!=b && a!=-1 && b!=-1) {
		a=parent[a];
		b=parent[b];
		++cnt;
	}
	if(depth[1]==depth[2]&&cnt==1) cout << "SIBLINGS" << '\n';
	else if(a==-1 || b==-1) cout << "NOT RELATED" << '\n';
	else if(cnt==0) {
		if(abs(depth[1]-depth[2])==1) {
			if(depth[1]<depth[2]) cout << A << " is the mother of " << B << '\n';
			else cout << B << " is the mother of " << A << '\n';
		}
		else if(abs(depth[1]-depth[2])==2) {
			if(depth[1]<depth[2]) cout << A << " is the grand-mother of " << B << '\n';
			else cout << B << " is the grand-mother of " << A << '\n';
		}
		else {
			if(depth[1]<depth[2]) {
				cout << A << " is the ";
				for(int i=0; i<depth[2]-depth[1]-2; ++i) cout << "great-";
				cout << "grand-mother of " << B << '\n';
			}
			else {
				cout << B << " is the ";
				for(int i=0; i<depth[1]-depth[2]-2; ++i) cout << "great-";
				cout << "grand-mother of " << A << '\n';
			}
		}
	}
	else if(cnt==1) {
		if(depth[1]<depth[2]) {
			cout << A << " is the ";
			for(int i=0; i<depth[2]-depth[1]-1; ++i) cout << "great-";
			cout << "aunt of " << B << '\n';
		}
		else {
			cout << B << " is the ";
			for(int i=0; i<depth[1]-depth[2]-1; ++i) cout << "great-";
			cout << "aunt of " << A << '\n';
		}
		
	}
	else if(a!=-1&&b!=-1) cout << "COUSINS" << '\n';
}