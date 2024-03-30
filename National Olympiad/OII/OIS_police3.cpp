#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
#define s second
#define f first

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> a(n+1),dp(n+1,1e9);
    for(int i=1;i<=n;i++) cin >> a[i];
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1]+a[i];
        if(i > 1) dp[i] = min(dp[i],dp[i-2]+a[i]);
    }
    cout << min(dp[n-1],dp[n]);
    return 0;
}
