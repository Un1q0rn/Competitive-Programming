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
    setIO("pairup");
    int n;cin >> n;
    vector<pair<ll,ll>> cow;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll x,y;cin >> x >> y;
        cow.pb({x,y});
    }
    sort(all(cow),[](auto &a,auto &b){
            return a.s < b.s;
            });
    int l = 0,r = sz(cow)-1;
    while(l < r){
        ans = max(cow[l].s+cow[r].s,ans);
        int t = min(cow[l].f,cow[r].f);
        cow[l].f -= t;
        cow[r].f -= t;
        if(cow[l].f == 0) l++;
        if(cow[r].f == 0) r--;
    }
    if(l == r && cow[l].f > 2) ans = max(cow[l].s*2,ans);
    cout << ans;
    return 0;
}
