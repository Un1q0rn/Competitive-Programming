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

const int inf = 1e9;
int main() {
    setIO("time");
    int n,m,c;
    cin >> n >> m >> c;
    vector<vector<int>> adj(n),dp(n,vector<int>(1e3+10,-inf));
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    while(m--){
        int u,v;cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
    }
    dp[0][0] = 0;
    int ans = 0;
    for(int t=1;t<=1000;t++){
        for(int u=0;u<n;u++){
            for(auto v:adj[u]){
                dp[v][t] = max(dp[v][t],dp[u][t - 1] + a[v]);
                if(v == 0){
                    ans = max(ans,dp[v][t] - c * t * t);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
