#include <bits/stdc++.h> 
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
#define setdecimal(x) cout << fixed << setprecision(x)

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("herding");
    int a,b,c;cin >> a >> b >> c;
    cout << (max(abs(a-b),abs(b-c)) > 1)+((min(abs(a-b),abs(b-c)) > 2 || min(abs(a-b),abs(b-c)) == 1) && max(abs(a-b),abs(b-c)) != 1) << '\n' << max(abs(a-b)-1,abs(b-c)-1) ; 
    return 0;
}
