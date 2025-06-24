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
    setIO("teamwork");
    int n,k;cin >> n >> k;
    vector<int> a(n + 1),dp(n + 1,-1e9);
    for(auto &e:a) cin >> e;

    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int mx = a[i - 1];
        for(int j=i;j>max(0,i - k);j--){
            mx = max(a[j - 1],mx);
            dp[i] = max(dp[i],mx * (i - j + 1) + dp[j - 1]);
        }
    }

    cout << dp[n];
    return 0;
}
