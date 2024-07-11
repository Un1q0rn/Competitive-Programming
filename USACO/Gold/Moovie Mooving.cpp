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
    setIO("movie");
    int n,L;cin >> n >> L;
    vector<ll> d(n),dp(1 << n,-1);
    vector<vector<ll>> a(n);
    for(int i=0;i<n;i++){
        int c;cin >> d[i] >> c;
        for(int j=0;j<c;j++){
            ll x;cin >> x;
            a[i].push_back(x);
        }
    }
    dp[0] = 0;
    int ans = 22;
    for(int i=0;i<(1<<n);i++){
        if(dp[i] == -1) continue;
        ll now = dp[i];
        if(now >= L){
            ans = min(ans,__builtin_popcount(i));
        }
        for(int j=0;j<n;j++){
            if(i & (1 << j)) continue;
            int mask = i | (1<<j);
            int l = 0,r = sz(a[j]) - 1;
            while(l < r){
                int mid = (l+r+1)>>1;
                if(a[j][mid] <= now){
                    l = mid;
                }
                else r = mid - 1;
            }
            if(a[j][r] > now) continue;
            dp[mask] = max(dp[mask],a[j][r] + d[j]);
        }
    }
    cout << (ans == 22 ? -1 : ans);
    return 0;
}
