#include<iostream>

using namespace std;

int board[19][19];

int dy[]={0, 0, 1, 1, 1, -1, -1, -1};
int dx[]={1, -1, 0, 1, -1, 0, 1, -1};

bool valid(int y, int x) {
	return 0<=y&&y<19&&0<=x&&x<19;
}

int main(void) {
	for(int i=0; i<19; ++i) for(int j=0; j<19; ++j) cin >> board[i][j];
	for(int i=0; i<19; ++i) for(int j=0; j<19; ++j) {
		for(int i=0; i<8; ++i) {
			int ny=i+dy[i], nx=j+dx[i];
		}
	}
}