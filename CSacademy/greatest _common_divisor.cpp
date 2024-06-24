#include <bits/stdc++.h>
using namespace std;
 
 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

int gcd(int a,int b) {return b == 0 ? a:gcd(b,a%b);}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int a,b;cin >> a >> b;
    cout << gcd(a,b);
    return 0;
}
