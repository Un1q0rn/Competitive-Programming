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
    setIO("reststops");
    ll l,n,rf,rb;cin >> l >> n >> rf >> rb;
    vector<pair<ll,ll>> a(n),b;
    for(int i=0;i<n;i++){
        cin >> a[i].second >> a[i].first;
    }
    sort(all(a),greater<pair<ll,ll>>());
    for(int i=0;i<n;i++){
        if(i == 0){
            b.push_back(a[i]);
            continue;
        }
        if(a[i].second > b.back().second){
            b.push_back(a[i]);
        }
    }
    ll ans = 0,lst = 0;
    for(auto [f,s]:b){
        ll fs = (s-lst)*rf,bs = (s-lst)*rb;
        ans += f*(fs-bs);
        lst = s;
    }
    cout << ans;
    return 0;
}
