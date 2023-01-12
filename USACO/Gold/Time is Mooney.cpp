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
#define ld long double

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("time");
    int n,m,c;cin >> n >> m >> c;
    vector<int> a(n);
    vector<vector<int>> adj(n);
    for(auto &e:a) cin >> e;
    while(m--){
        int u,v;cin >> u >> v;
        adj[--u].pb(--v);
    }
    vector<vector<int>> dp(1010,vector<int>(n,-1));
    dp[0][0] = 0;
    int ans = 0;
    for(int i=0;i<=1000;i++){
        for(int u=0;u<n;u++){
            if(dp[i][u] == -1) continue;
            for(auto v:adj[u]){
                dp[i+1][v] = max(dp[i+1][v],dp[i][u]+a[v]);
            }
        }
        ans = max(ans,dp[i][0]-(c*i*i));
    }
    cout << ans;
    return 0; 
}
