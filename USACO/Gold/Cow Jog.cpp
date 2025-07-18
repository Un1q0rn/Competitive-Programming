
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
    setIO("cowjog");
    ll n,t;cin >> n >> t;
    vector<ll> x;
    for(int i=0;i<n;i++){
        ll a,b;cin >> a >> b;
        x.push_back({-(a + t * b)});
    }

    int ans = 0;
    vector<ll> lis;
    for(int i=0;i<n;i++){
        int p = upper_bound(all(lis),x[i]) - lis.begin();
        if(p == sz(lis)){
            lis.push_back(x[i]);
        }
        else{
            lis[p] = x[i];
        }
    }
    cout << sz(lis);
    return 0;
}
