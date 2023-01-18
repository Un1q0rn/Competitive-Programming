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
    setIO("lazy");
    int n,k;cin >> n >> k;
    vector<vector<int>> a(n+1,vector<int>(n+1)),dp(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            dp[i][j]=dp[i-1][j]+a[i][j];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            int l = j-1,r = j+1,cnt = k-1;
            int res = 0;
            while(cnt>=0){
                if(l >= 1){
                    res+=dp[min(i+cnt,n)][l]-dp[max(0,i-cnt-1)][l];
                    l--;
                }
                if(r <= n){
                    res+=dp[min(i+cnt,n)][r]-dp[max(0,i-cnt-1)][r];
                    r++;
                }
                cnt--;
            }
            res+=dp[min(i+k,n)][j]-dp[max(0,i-k-1)][j];
            ans = max(res,ans);
        }
    }
    cout << ans;
    return 0; 
}
