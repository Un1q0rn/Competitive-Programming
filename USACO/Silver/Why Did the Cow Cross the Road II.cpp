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
    setIO("maxcross");
    int n,k,b;cin >> n >> k >> b;
    vi(int) a(n+1);
    while(b--){
        int x;cin >> x;
        a[x]++;
    }
    FOR(i,1,n){
        a[i]+=a[i-1];
    }
    int ans = 1e9;
    FOR(i,0,n-k){
        ans = min(ans,a[i+k]-a[i]);
    }
    cout << ans;
    return 0;
}
