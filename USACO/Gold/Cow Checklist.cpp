
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

const int MAXN = 1e3 + 10;
ll dp[2][MAXN][MAXN];

int main() {
    setIO("checklist");
    int n,m;cin >> n >> m;
    vector<pair<ll,ll>> h(n + 1),g(m + 1);
    for(int i=1;i<=n;i++){
        cin >> h[i].f >> h[i].s;
    }
    for(int i=1;i<=m;i++){
        cin >> g[i].f >> g[i].s;
    }
    h[0] = h[1];
    g[0] = g[1];

    auto dist = [&](pair<ll,ll> a,pair<ll,ll> b) -> ll{
        return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
    };

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = dp[0][1][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i > 1) dp[0][i][j] = min(dp[0][i][j],dp[0][i - 1][j] + dist(h[i],h[i - 1]));
            if(i > 1) dp[0][i][j] = min(dp[0][i][j],dp[1][i - 1][j] + dist(h[i],g[j]));
            if(j > 1) dp[1][i][j] = min(dp[1][i][j],dp[1][i][j - 1] + dist(g[j],g[j - 1]));
            if(j > 0) dp[1][i][j] = min(dp[1][i][j],dp[0][i][j - 1] + dist(g[j],h[i]));
        }
    }

    cout << dp[0][n][m];
    return 0;
}
