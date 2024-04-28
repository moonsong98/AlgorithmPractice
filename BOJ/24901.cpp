#include<bits/stdc++.h>
#define a /*
a = gets.to_i
if a >= 0
    print 0
end
if a >= 1
    print 1
end
if a >= 2
    print 10
end
if a >= 3
    print 11
end
if a >= 4
    print 100
end
if a >= 5
    print 101
end
if a >= 6
    print 110
end
if a >= 7
    print 111
end
if a >= 8
    print 1000
end
if a >= 9
    print 1001
end
if a >= 10
    print 1010
end
#*/


#define d=begin

using namespace std; 

string arr[11] = {
	"0",
	"1",
	"10",
	"11",
	"100",
	"101",
	"110",
	"111",
	"1000",
	"1001",
	"1010",
};

int main(void) {
	int n;
	cin >> n;
	for(int i=0; i<=n; ++i) 
		cout << arr[i];
}
#
#define c=end

#