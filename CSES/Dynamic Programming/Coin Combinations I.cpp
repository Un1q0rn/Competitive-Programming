#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
#define s second
#define f first

const int M = 1e9+7;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,x;cin >> n >> x;
    vector<int> dp(x+1),a(n);
    for(auto &e:a) cin >> e;
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(auto c:a){
            if(i-c >= 0) dp[i] += dp[i-c];
            dp[i] %= M;
        }
    }
    cout << dp[x];
    return 0;
}
