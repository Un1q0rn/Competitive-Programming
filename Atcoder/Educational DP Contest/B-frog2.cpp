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
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin >> n >> k;
    vector<int> height(n+1),dp(n+1,INT_MAX);
    for(int i=1;i<=n;i++){
        cin >> height[i];
    }
    dp[1] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i+j <= n){
                dp[i+j] = min(dp[i+j],dp[i]+abs(height[i]-height[i+j]));
            }
        }
    }
    cout << dp[n];
    return 0;
}
