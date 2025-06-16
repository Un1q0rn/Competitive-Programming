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

void solve(){
    int n;cin >> n;
    vector<ll> a(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    ll ans = 1e18;
    int k = n / 2 + 1;
    for(int i=0;i<=n - k;i++){
        ans = min(ans,a[i + k] - a[i]);
    }
    cout << ans << ' ' << a[n] - ans << '\n';
}

int main() {
    setIO("");
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
