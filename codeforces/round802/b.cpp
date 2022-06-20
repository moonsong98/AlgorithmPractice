#include<bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
using namespace std;

int ctoi(char a) {
    return a-'0';
}

char itoc(int n) {
    return n+'0';
}

string add(string& a, string& b) {
    string ans;
    int carry=0;
    reverse(all(a));
    reverse(all(b));
    for(int i=0, len=sz(a); i<len; ++i) {
        int nxt=ctoi(a[i])+ctoi(b[i])+carry;
        if(nxt>=10) {
            ans.push_back(itoc(nxt%10));
            carry=nxt/10;
        }
        else {
            ans.push_back(itoc(nxt));
            carry=0;
        }
    }
    if(carry!=0)
        ans.push_back(itoc(carry));
    reverse(all(a));
    reverse(all(b));
    reverse(all(ans));
    return ans;
}

string sub(string& a, string& b) {
    reverse(all(a));
    reverse(all(b));
    string ans;
    int borrow=0;
    while(sz(b)<sz(a)) b.push_back('0');
    for(int i=0, len=sz(a); i<len; ++i) {
        int nxt=ctoi(a[i])-ctoi(b[i])-borrow;
        if(nxt<0) {
            borrow=-1*(nxt-9)/10;
            ans.push_back(itoc(nxt+borrow*10));
        }
        else {
            ans.push_back(itoc(nxt));
            borrow=0;
        }
    }
    for(int i=sz(ans)-1; i>=0; --i) {
        if(ans[i]!='0') break;
        ans.pop_back();
    }
    reverse(all(ans));
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n;
        string a;
        cin >> n >> a;
        string m(sz(a), '0'), M(sz(a), '9');
        m[0]='1';
        string lb=add(m, a);
        string ub=add(M, a);
        string pal;
        if(lb==M) {
            pal=string(sz(lb)+1, '0');
            pal[0]=pal[sz(lb)]='1';
        }
        else {
            pal=string(sz(lb), '0');
            if(sz(lb)==sz(ub)) {
                pal[0]=lb[0];
                for(int i=1; i<(sz(lb)+1)/2; ++i) {
                    if(lb[i]=='9') pal[i]=lb[i];
                    else pal[i]=lb[i]+1;
                }
                for(int i=sz(lb)/2; i<sz(lb); ++i)
                    pal[i]=pal[sz(pal)-i-1];
            }
            else {
                for(int i=0; i<sz(lb)/2; ++i) {
                    if(lb[i]=='9') pal[i]=lb[i];
                    else pal[i]=lb[i]+1;
                }
                for(int i=sz(lb)/2; i<sz(lb); ++i)
                    pal[i]=pal[sz(pal)-i-1];
            }
        }
        string ans=sub(pal, a);
        cout << ans << '\n';
    }
}
