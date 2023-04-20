#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
#define s second
#define f first

const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k;cin >> n >> m >> k;
    vector<vector<ll>>  dp(m+1,vector<ll>(k+1,INF));
    vector<ll> a(m+1);
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a[x]++;
    }
    auto cal = [&](ll x,ll p){
        if(p == 0) return x*(x+1)/2;
        ll a = p - (x % p);
        ll b = (x % p);
        ll numa = x/p;
        ll numb = numa+1;
        return (a * (numa*(numa+1)/2)) + (b * (numb*(numb+1))/2);
    };
    dp[0][0] = 0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=k;j++){
            for(int p=0;p<=j;p++){
                dp[i][j] = min(dp[i][j],dp[i-1][j-p]+cal(a[i],p+1));
            }
        }
    }
    cout << dp[m][k];
    return 0;
}
