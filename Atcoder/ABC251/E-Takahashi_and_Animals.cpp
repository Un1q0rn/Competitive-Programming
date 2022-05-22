#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const int N = 3e5+100;
ll a[N],b[N],dp[N][2];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n; 
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    memset(dp,127,sizeof dp);
    dp[1][0] = a[1];
    for(int i=2;i<=n;i++){
        dp[i][1] = dp[i-1][0];
        dp[i][0] = min(dp[i-1][0],dp[i-1][1])+a[i];
    }
    ll ans = min(dp[n][0],dp[n][1]);
    memcpy(b,a,sizeof a);
    for(int i=1;i<=n;i++){
        a[i] = b[(i-2+n)%n+1];
    }
    memset(dp,127,sizeof dp);
    dp[1][0] = a[1];
    for(int i=2;i<=n;i++){
        dp[i][1] = dp[i-1][0];
        dp[i][0] = min(dp[i-1][0],dp[i-1][1])+a[i];
    }
    ans = min({ans,dp[n][0],dp[n][1]});
    cout << ans << '\n';
    return 0;
}
