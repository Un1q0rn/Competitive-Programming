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
    setIO("feast");
    ll t,a,b;cin >> t >> a >> b;
    vector<vector<int>> dp(t+1,vector<int>(2));
    dp[0][0] = 1;
    int ans = 0;
    for(int i=0;i<=t;i++){
        if((i-a >= 0 && dp[i-a][0]) || (i-b >= 0 && dp[i-b][0])) dp[i][0] = 1;
        if(dp[i][0]) {
            dp[i/2][1] = 1;
        }
    }
    for(int i=0;i<=t;i++){
        if((i-a >= 0 && dp[i-a][1]) || (i-b >= 0 && dp[i-b][1])) dp[i][1] = 1;
    }
    for(int i=0;i<=t;i++){
        if(dp[i][0] || dp[i][1]) ans = max(ans,i);
    }
    cout << ans;
    return 0; 
}
