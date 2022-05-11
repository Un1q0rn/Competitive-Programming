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
    for(int i=1;i<=n;i++){
        cin >> dp[i];
        dp[i]+=dp[i-1];
    }
    map<ll,ll> m;
    ll ans = 0;
    for(int i=0;i<=n;i++){
        if(m.count(dp[i]-x)){
            ans+=m[dp[i]-x];
        }
        m[dp[i]]++;
    }
    cout << ans << '\n';
    return 0;
}
