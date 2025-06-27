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
    setIO("248");
    int n;cin >> n;
    vector<int> a(n);
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        cin >> a[i];
        dp[i][i] = a[i];
    }

    int ans = -1;
    for(int sz = 2;sz <= n;sz++){
        for(int i = 0;i <= n - sz;i++){
            int j = i + sz - 1;
            for(int k = i;k < j;k++){
                if(dp[i][k] == dp[k + 1][j]){
                    dp[i][j] = max(dp[i][j],dp[i][k] + 1);
                    ans = max(ans,dp[i][j]);
                }
            }
        }
    }

    cout << ans;
    return 0;
}
 
