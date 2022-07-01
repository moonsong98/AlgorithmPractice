#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vector<string> board(N);
    vector<vector<int> > state(N, vector<int>(N, -1));
    for(int i=0; i<N; ++i) cin >> board[i];
    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
        if(board[i][j]=='X') state[i][j]=1;
        else if(board[i][j]=='.') state[i][j]=0;
        else if(board[i][j]=='O') state[i][j]=2;
    }
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) 
            if(state[i][j]==2) {
                ++j;
                for(; j<N; ++j) {
                    if(state[i][j]==1||state[i][j]==2) {
                        --j;
                        break;
                    }
                    state[i][j]=3;
                }
            }
        for(int j=0; j<N; ++j) 
            if(state[j][i]==2) {
                ++j;
                for(; j<N; ++j) {
                    if(state[j][i]==1||state[j][i]==2) {
                        --j;
                        break;
                    }
                    state[j][i]=3;
                }
            }
        for(int j=N-1; j>=0; --j) 
            if(state[i][j]==2) {
                --j;
                for(; j>=0; --j) {
                    if(state[i][j]==1||state[i][j]==2) {
                        ++j;
                        break;
                    }
                    state[i][j]=3;
                }
            }
        for(int j=N-1; j>=0; --j) 
            if(state[j][i]==2) {
                --j;
                for(; j>=0; --j) {
                    if(state[j][i]==1||state[j][i]==2) {
                        ++j;
                        break;
                    }
                    state[j][i]=3;
                }
            }
    }
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            switch(state[i][j]) {
                case 0: 
                    cout << 'B';
                    break;
                case 1: 
                    cout << 'X';
                    break;
                case 2: 
                    cout << 'O';
                    break;
                case 3: 
                    cout << '.';
                    break;
            }
        }
        cout << '\n';
    }
}
