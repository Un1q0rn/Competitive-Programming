
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
ll dp[MAXN][MAXN];

int main() {
    setIO("nocross");
    int n;cin >> n;
    vector<int> a(n),b(n);
    for(auto &e:a) cin >> e;
    for(auto &e:b) cin >> e;

    for(int i=0;i<n;i++){
        if(abs(a[i] - b[0]) <= 4) dp[i][0] = 1;
        if(abs(b[i] - a[0]) <= 4) dp[0][i] = 1;
        if(i){
            dp[i][0] = max(dp[i][0],dp[i - 1][0]);
            dp[0][i] = max(dp[0][i],dp[0][i - 1]);
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(abs(a[i] - b[j]) <= 4){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[n - 1][n - 1];
    return 0;
}
