#include<iostream>

using namespace std;

bool isPossible(int n, int m, int kh, int kv){
	if(n&1){
		kh-=m/2;
		if(kh<0) return false;
	}
	if(m&1){
		kv-=n/2;
		if(kv<0) return false;
	}
	if(kh&1||kv&1)
		return false;
	return true;
}

void init(char board[101][101], int n, int m){
	for(int i=0;i<n;++i)	
		for(int j=0;j<m;++j)
			board[i][j]=' ';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n, m, kh, kv;
		cin>>n>>m>>kh;
		kv=n*m/2-kh;
		bool possible = isPossible(n, m, kh, kv);
		if(!possible){
			cout<<"NO"<<endl;
			continue;
		}
		char board[101][101];
		init(board,n,m);
		
		int printN=n, printM=m;
		if(n&1){
			for(int i=0; i<m; i+=2){
				char cover='w'+(i/2)%2;
				board[n-1][i] = board[n-1][i+1]=cover;
			}
			kh-=m/2;
			n-=1;
		}
		if(m&1){
			for(int i=0; i<n; i+=2){
				char cover='w'+(i/2)%2;
				board[i][m-1] = board[i+1][m-1]=cover;
			}
			kv-=n/2;
			m-=1;
		}
		
		//cover even*even
		int firstCell=0;
		while(kh>0){
			for(int i=0; i<n&&kh>0; ++i, --kh){
				board[i][firstCell]=board[i][firstCell+1]='a'+(i+firstCell/2)%2;
			}
			firstCell+=2;
		}
		for(int i=0; i<n; i+=2){
			for(int j=0; j<m; ++j){
				if(board[i][j]>='a') continue;
				else{
					char cover='c'+(i/2+j)%2;
					board[i][j]=board[i+1][j]=cover;
				}
			}
		}
		
		cout<<"YES"<<endl;
		for(int i=0; i<printN; ++i) {
			for(int j=0; j<printM; ++j)
				cout<<board[i][j];
			cout<<endl;
		}
	}
}