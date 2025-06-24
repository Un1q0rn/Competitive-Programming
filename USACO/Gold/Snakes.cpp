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
    setIO("snakes");
    int n,K;cin >> n >> K;
    vector<int> a(n + 1),p(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        p[i] += p[i - 1] + a[i];
    }

    vector<vector<int>> dp(n + 1,vector<int>(K + 1,1e9));
    dp[0][0] = 0;
    int mx = -1e9;
    for(int i=1;i<=n;i++){
        mx = max(mx,a[i]);
        dp[i][0] = mx * i - p[i];
    }

    for(int k=1;k<=K;k++){
        for(int i=1;i<=n;i++){
            mx = a[i];
            for(int j=i;j>0;j--){
                mx = max(mx,a[j]);
                dp[i][k] = min(dp[i][k],dp[j - 1][k - 1] + (mx * (i - j + 1) - (p[i] - p[j - 1])));
            }
        }
    }
    cout << dp[n][K];
    return 0;
}

