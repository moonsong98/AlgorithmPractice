#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string A, B;
int cache[1001][1001];

void printPath(int a, int b) {
	if(!cache[a][b])return;
	if(a==-1) printPath(a+1, b+1);
	else if(A[a]==B[b]){
		cout<<A[a];
		printPath(a+1,b+1);
	}
	else
		cache[a+1][b]>cache[a][b+1]?printPath(a+1,b):printPath(a,b+1);
}

int lcs(int a, int b) {
	if(a==A.size()||b==B.size()) return 0;
	int& ret=cache[a+1][b+1];
	if(ret!=-1) return ret;
	if(a==-1||A[a]==B[b])
		ret=lcs(a+1,b+1)+1;
	else
		ret=max(lcs(a+1,b),lcs(a,b+1));
	return ret;
}

int main(void) {
	memset(cache,-1,sizeof(cache));
	cin >> A >> B;
	int ans = lcs(-1,-1)-1;
	cout << ans << endl;
	if(ans){
		printPath(-1,-1);
	}
}