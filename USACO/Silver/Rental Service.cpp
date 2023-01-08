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
    setIO("rental");
    ll n,m,r;cin >> n >> m >> r;
    vector<ll> milk(n),rent(r);
    vector<pair<ll,ll>> shop(m);
    for(auto &e:milk) cin >> e;
    for(auto &[x,y]:shop){
        cin >> y >> x;
    }
    for(auto &e:rent) cin >> e;
    sort(all(milk),greater<ll>());
    sort(all(shop),[](pair<ll,ll> &a,pair<ll,ll> &b){
            return a.f > b.f;
            });
    sort(all(rent),greater<ll>());
    vector<ll> money(n+1);
    ll p = 0;
    for(ll i=0;i<n;i++){
        money[i+1] = money[i];
        while(p < m && milk[i] > 0){
            ll sell = min(milk[i],shop[p].second);
            money[i+1] += shop[p].first*sell;
            milk[i]-=sell;
            shop[p].second -= sell;
            if(shop[p].second == 0) p++;
        }
    }
    p = 0;
    ll i = n-1,rentearn = 0;
    while(p < r && i >= 0){
        rentearn += rent[p];
        money[i] += rentearn;
        p++,i--;
    }
    ll ans = *max_element(all(money));
    cout << ans;
    return 0;
}
