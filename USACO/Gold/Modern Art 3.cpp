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
    setIO("");
    int n;cin >> n;
    vector<int> a(n);
    vector<vector<int>> dp(n,vector<int>(n));
    for(auto &e:a) cin >> e;
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
    }
    for(int sz=2;sz<=n;sz++){
        for(int i=0;i<=n-sz;i++){
            int j = i + sz - 1;
            dp[i][j] = dp[i + 1][j] + 1;
            for(int k=i+1;k<=j;k++){
                if(a[i] == a[k]){
                    dp[i][j] = min(dp[i][j],dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}
