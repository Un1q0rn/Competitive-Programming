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
    setIO("radio");
    int n,m;cin >> n >> m;
    pair<int,int> fj,bs;
    cin >> fj.first >> fj.second >> bs.first >> bs.second;
    string s,t;cin >> s >> t;
    s = " " + s;
    t = " " + t;
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
    auto step = [&](pair<int,int> x,char d){
        x.first += (d == 'E');
        x.first -= (d == 'W');
        x.second += (d == 'N');
        x.second -= (d == 'S');
        return x;
    };
    auto dist = [&](pair<int,int> x,pair<int,int> y){
        return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
    };
    auto nfj = fj;
    dp[0][0] = 0;
    for(int i=0;i<=n;i++){
        auto nbs = bs;
        nfj = step(nfj,s[i]);
        for(int j=0;j<=m;j++){
            nbs = step(nbs,t[j]);
            if(i + 1 <= n){
                dp[i+1][j] = min(dp[i+1][j],dp[i][j] + dist(step(nfj,s[i+1]),nbs));
            }
            if(j + 1 <= m){
                dp[i][j+1] = min(dp[i][j+1],dp[i][j] + dist(nfj,step(nbs,t[j+1])));
            }
            if(i + 1 <= n && j + 1 <= m){
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j] + dist(step(nfj,s[i+1]),step(nbs,t[j+1])));
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
