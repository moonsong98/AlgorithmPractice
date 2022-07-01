#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    string str;
    cin >> n;
    cin >> str;
    char st=str[0];
    int cur=n-1;
    bool up=false;
    for(int i=0; i<(1<<n); ++i) {
        cout << str << '\n';
        if(str[0]==st) {
            for(char &ch:str) {
                if(ch=='1') ch='0';
                else ch='1';
            }
        }
        else {
            for(int i=0; i<n; ++i) {
                if(i==cur) continue;
                if(str[i]=='1') str[i]='0';
                else str[i]='1';
            }
            if(cur==n-1) {
                --cur;
                up=false;
            }
            else if(cur==1) {
                ++cur;
                up=true;
            }
            else {
                if(up) ++cur;
                else --cur;
            }
        }
    }
}
