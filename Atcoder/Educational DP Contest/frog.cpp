#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
#define pb push_back

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> height(n+1),dp(n+1,INT_MAX);
    for(int i=1;i<=n;i++){
        cin >> height[i];
    }
    dp[1] = 0;
    for(int i=1;i<=n;i++){
        if(i+1<=n){
            dp[i+1] = min(dp[i+1],dp[i]+abs(height[i]-height[i+1]));
        }
        if(i+2<=n){
            dp[i+2] = min(dp[i+2],dp[i]+abs(height[i]-height[i+2]));
        }
    }
    cout << dp[n];
    return 0;
}
