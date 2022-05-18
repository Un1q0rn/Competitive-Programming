#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define ui unsigned int 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
#define sz(x) (int)x.size()
const int N = 1e5+10;
int dp[N][3];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        int a,b,c;cin >> a >> b >> c;
        dp[i][0] = max(dp[i-1][1]+a,dp[i-1][2]+a);
        dp[i][1] = max(dp[i-1][0]+b,dp[i-1][2]+b);
        dp[i][2] = max(dp[i-1][1]+c,dp[i-1][0]+c);
    }
    cout << max({ dp[n][0],dp[n][1],dp[n][2] });
    return 0;
}
