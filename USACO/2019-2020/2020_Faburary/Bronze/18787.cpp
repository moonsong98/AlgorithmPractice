#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    string A, B;
    cin >> N >> A >> B;
    int ans=0; bool isConsistent=true;
    for(int i=0; i<N; ++i) {
        if(A[i]!=B[i]) {
            if(isConsistent) ++ans;
            isConsistent=false;
        }
        else isConsistent=true;
    }
    cout << ans << '\n';
    return 0;
}
