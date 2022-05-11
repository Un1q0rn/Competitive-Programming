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
    ll n,x;cin >> n >> x;
    vector<ll> dp(n+2);
    map<ll,ll> m;
    m[0] = 1;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cin >> dp[i];
        dp[i]+=dp[i-1];
        ans+=m[dp[i]-x];
        m[dp[i]]++;
    }
    cout << ans;
    return 0;
}
