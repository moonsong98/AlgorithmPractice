#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> ans;

void cover(int y, int x, int size) {
	if(size == 2) {
		for(int i=x; i<x+5; ++i) ans[y][i]=true;
		for(int i=y+1; i+1<y+7; ++i) ans[i][x]=true;
		for(int i=x; i<x+5; ++i) ans[y+6][i]=true;
		for(int i=y+2; i+1<y+7; ++i) ans[i][x+4]=true;
		ans[y+2][x+2]=ans[y+2][x+3]=ans[y+3][x+2]=ans[y+4][x+2]=true;
		return;
	}
	for(int i=x; i<x+5+4*(size-2); ++i) ans[y][i]=true;
	for(int i=y+1; i+1<y+7+4*(size-2); ++i) ans[i][x]=true;
	for(int i=x; i<x+5+4*(size-2); ++i) ans[y+7+4*(size-2)-1][i]=true;
	for(int i=y+2; i+1<y+7+4*(size-2); ++i) ans[i][x+5+4*(size-2)-1]=true;
	ans[y+2][x+5+4*(size-2)-2]=true;
	cover(y+2,x+2,size-1);
}

int main(void) {
	int n;
	cin >> n;
	if(n==1) {
		cout << "*" << '\n';
		return 0;
	}
	int nRow=(n-2)*4+7, nCol=(n-2)*4+5;
	ans=vector<vector<bool>>(nRow, vector<bool>(nCol,false));
	
	cover(0, 0, n);
	for(int i=0; i<nRow; ++i) {
		if(i==1) {
			cout << (ans[i][0]?'*':' ') << '\n';
			continue;
		}
		for(int j=0; j<nCol; ++j) cout << (ans[i][j]?'*':' ');
		cout << '\n';
	}
}