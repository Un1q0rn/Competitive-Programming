#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[i] = min(dp[i],dp[max(i-1,0)]+500);
        dp[i] = min(dp[i],dp[max(i-2,0)]+800);
        dp[i] = min(dp[i],dp[max(i-5,0)]+1500);
        dp[i] = min(dp[i],dp[max(i-15,0)]+3000);
    }
    cout << dp[n] << '\n';
    return 0;
}
