#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
const int MOD = 1e9+7;
ll dp[N];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    dp[0] = dp[1] = 1;
    for(int i=2;i<=N-10;i++){
        dp[i] = dp[i-1]*i;
        dp[i] %= MOD;
    }
    while(t--){
        int n;cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
