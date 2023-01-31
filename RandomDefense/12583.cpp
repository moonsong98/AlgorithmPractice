#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    for(int t = 1; t <= T; ++t) {
        bool redWin = false, blueWin = false;

        int N, K; cin >> N >> K;
        //Board Creation
        vector<string> board(N, string(N, '.'));
        for(int i=0; i<N; ++i) {
            string letters;
            for(int j=0; j<N; ++j){
                char ch; cin >> ch;
                if(ch != '.') letters.push_back(ch);
            }
            for(int j=0; j<N-letters.size(); ++j) board[i][j]='.';
            for(int j=0; j<letters.size(); ++j) board[i][N-letters.size()+j] = letters[j];
        }

        //Check Who Wins
        //Horizontal
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j){
                if(board[i][j] == '.') continue;
                int cntRed=board[i][j]=='R', cntBlue=board[i][j]=='B';
                ++j;
                for(; j<N; ++j) {
                    if(board[i][j]=='R') ++cntRed;
                    else if(board[i][j] == 'B') ++cntBlue;
                    else break;
                }
                if(cntRed >= K) redWin = true;
                if(cntBlue >= K) blueWin = true;
            }
        }
        //Vertical
        for(int j=0; j<N; ++j) {
            for(int i=0; i<N; ++i){
                if(board[i][j] == '.') continue;
                int cntRed=board[i][j]=='R', cntBlue=board[i][j]=='B';
                ++i;
                for(; i<N; ++i) {
                    if(board[i][j]=='R') ++cntRed;
                    else if(board[i][j] == 'B') ++cntBlue;
                    else break;
                }
                if(cntRed >= K) redWin = true;
                if(cntBlue >= K) blueWin = true;
            }
        }
        //Diagonal1
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                if(N-i<K || N-j<K) continue;
                int cntRed=board[i][j]=='R', cntBlue=board[i][j]=='B';
                for(int k=1; k<min(N-i, N-j); ++k) {
                    if(board[i+k][j+k]=='R') ++cntRed;
                    else if(board[i+k][j+k] == 'B') ++cntBlue;
                    else break;
                }
                if(cntRed >= K) redWin = true;
                if(cntBlue >= K) blueWin = true;
            }
        }
        //Diagonal2
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                if(N-i<K || j+1<K) continue;
                int cntRed=board[i][j]=='R', cntBlue=board[i][j]=='B';
                for(int k=1; k<min(N-i, j+1); ++k) {
                    if(board[i+k][j-k]=='R') ++cntRed;
                    else if(board[i+k][j-k] == 'B') ++cntBlue;
                    else break;
                }
                if(cntRed >= K) redWin = true;
                if(cntBlue >= K) blueWin = true;
            }
        }

        for(int i=0; i<N; ++i)
            cout << board[i] << '\n';

        cout << "Case #" << t <<": ";
        if(redWin) {
            if(blueWin) cout << "Both" << '\n';
            else cout << "Red" << '\n';
        }
        else {
            if(blueWin) cout << "Blue" << '\n';
            else cout << "Neither" << '\n';
        }
    }
}
