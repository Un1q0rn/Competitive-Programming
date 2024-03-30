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
    int n,x;cin >> n >> x;
    vector<int> dp(x+1,1e9),a(n);
    for(auto &e:a) cin >> e;
    dp[0] = 0;
    for(int i=1;i<=x;i++){
        for(auto c:a){
            if(i-c >= 0) dp[i] = min(dp[i-c]+1,dp[i]);
        }
    }
    cout << (dp[x] == 1e9 ? -1:dp[x]);
    return 0;
}
