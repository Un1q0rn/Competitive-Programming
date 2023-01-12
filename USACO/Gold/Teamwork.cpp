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
    setIO("teamwork");
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    vector<int> dp(n);
    for(int i=0;i<n;i++){
        int mx = a[i];
        for(int j=i;j>=max(0,i-k+1);j--){
            mx = max(mx,a[j]);
            dp[i] = max(dp[i],(j > 0 ? dp[j-1]:0)+(mx*(i-j+1)));
        }
    }
    cout << dp[n-1];
    return 0; 
}
