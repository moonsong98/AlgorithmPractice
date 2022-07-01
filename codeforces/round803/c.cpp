/*
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v, pos, neg;
        int numZero=0;
        for(int i=0; i<n; ++i) {
            int num; cin >> num;
            if(num>0) pos.push_back(num);
            else if(num<0) neg.push_back(num);
            else ++numZero;
        }
        if(sz(pos)>2||sz(neg)>2) {
            cout << "NO" << '\n';
            continue;
        } 
        bool ans=true;
        for(int i=0; i<sz(pos); ++i)
            v.push_back(pos[i]);
        for(int i=0; i<sz(neg); ++i)
            v.push_back(neg[i]);
        for(int i=0; i<min(2,numZero); ++i)
            v.push_back(0);
        for(int i=0; i<sz(v); ++i)
            for(int j=i+1; j<sz(v); ++j)
                for(int k=j+1; k<sz(v); ++k) {
                    int sum=v[i]+v[j]+v[k];
                    bool isExist=false;
                    for(int l=0; l<sz(v); ++l)
                        if(sum==v[l])
                            isExist=true;
                    ans&=isExist;
                }
        cout << (ans?"YES":"NO") << '\n';
    }
}
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
 
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> pos, neg;
        bool isZero=false;
        for(int i=0; i<n; ++i) {
            int num; cin >> num;
            if(num>0) pos.push_back(num);
            else if(num<0) neg.push_back(num);
            else isZero=true;
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
 
        bool ans=false;
        if(sz(pos)+sz(neg)<=1)
            ans=true;
        else if(sz(pos)==1&&sz(neg)==1&&pos[0]+neg[0]==0)
            ans=true;
        else if(sz(pos)==1&&sz(neg)==2&&isZero==false)  {
            int sum=pos[0]+neg[0]+neg[1];
            if(sum==neg[0]||sum==neg[1])
                ans=true;
        }
        else if(sz(neg)==1&&sz(pos)==2&&isZero==false) {
            int sum=neg[0]+pos[0]+pos[1];
            if(sum==pos[0]||sum==pos[1])
                ans=true;
        }
        else if(sz(pos)==2&&sz(neg)==2&&isZero==false) {
            vector<int> nums;
            bool valid=true;
            for(int a: pos) nums.push_back(a);
            for(int a: neg) nums.push_back(a);
            for(int i=0; i<4; ++i) {
                int sum=0;
                for(int j=0; j<4; ++j) {
                    if(i==j) continue;
                    sum+=nums[j];
                }
                bool isExist=false;
                for(int j=0; j<4; ++j) {
                    if(sum==nums[j])
                        isExist=true;
                }
                if(isExist==false)
                    valid=false;
            }
            ans=valid;
        }
        cout << (ans?"Yes":"No") << '\n';
    }
}
