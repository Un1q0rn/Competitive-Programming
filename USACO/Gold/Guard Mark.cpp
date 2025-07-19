
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
    setIO("guard");
    ll n,H;cin >> n >> H;
    vector<ll> h(n),w(n),s(n);
    for(int i=0;i<n;i++){
        cin >> h[i] >> w[i] >> s[i];
    }

    vector<ll> totw(1 << n),toth(1 << n),dp(1 << n,-1);
    for(int mask=1;mask<(1 << n);mask++){
        int p = __builtin_ctz(mask);
        int prev = mask ^ (1 << p);
        totw[mask] = totw[prev] + w[p];
        toth[mask] = toth[prev] + h[p];
    }

    dp[0] = 1e18;
    for(int mask = 1;mask < (1 << n);mask++){
        for(int i=0;i<n;i++){
            if(!(mask & (1 << i))) continue;
            int prev = mask ^ (1 << i);
            if(dp[prev] != -1 && s[i] >= totw[prev]){
                ll res = min(dp[prev],s[i] - totw[prev]);
                dp[mask] = max(dp[mask],res);
            }
        }
    }

    ll ans = -1;
    for(int mask = 1;mask < (1 << n);mask++){
        if(dp[mask] != -1 && toth[mask] >= H){
            ans = max(ans,dp[mask]);
        }
    }

    if(ans == -1){
        cout << "Mark is too tall";
    }
    else cout << ans;
    return 0;
}
