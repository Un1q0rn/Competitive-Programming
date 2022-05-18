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
ll w[110],v[110],dp[110][N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,W;cin >> n >> W;
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(j >= w[i]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][W];
    return 0;
}
