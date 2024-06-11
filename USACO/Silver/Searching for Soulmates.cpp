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
    ll a,b;cin >> a >> b;
    ll ans = 1e18;
    ll cnt1 = 0,cnt2 = 0;
    while(b){
        while(a > b){
            cnt1 += (a%2);
            a += (a%2);
            a >>= 1;
            cnt1++;
        }
        ans = min(ans,cnt1+cnt2+b-a);
        cnt2 += (b%2);
        b -= (b%2);
        b >>= 1;
        cnt2++;
    }
    cout << ans << '\n';
}

int main() {
    setIO("");
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
