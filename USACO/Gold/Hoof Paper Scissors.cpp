#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

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

const int N = 1e5+100;
int a[N],dp[N][25][3];
int main() {
    setIO("hps");
    int n,k;cin >> n >> k;
    for(int i=1;i<=n;i++){
        char c;cin >> c;
        if(c == 'H') a[i] = 0;
        if(c == 'P') a[i] = 1;
        if(c == 'S') a[i] = 2;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k+1;j++){
            for(int l=0;l<3;l++){
                if(l == a[i]) dp[i-1][j-1][l]++;
                dp[i][j][0] = max(dp[i][j][0],dp[i-1][j-1][l]);
                dp[i][j][1] = max(dp[i][j][1],dp[i-1][j-1][l]);
                dp[i][j][2] = max(dp[i][j][2],dp[i-1][j-1][l]);
                dp[i][j-1][l] = max(dp[i][j-1][l],dp[i-1][j-1][l]);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<3;i++){
        ans = max(ans,dp[n][k][i]);
    }
    cout << ans;
    return 0;
}
