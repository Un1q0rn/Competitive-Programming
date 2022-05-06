#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

const int N = 1e3+10;
ll dp[N][N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k;cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> dp[i][j];
            dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    ll ans = 0;
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            ll a =dp[i][j]-(dp[i-k][j]+dp[i][j-k]-dp[i-k][j-k]);
            ans = max(ans,a);
        }
    }
    cout << ans;
    return 0;
}
