#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
const int MOD = 1e9+7;
ll binpow(ll a,ll b,ll m){
    a %= m;
    ll res = 1;
    while(b){
        if(b&1){
            res = res * a % m;
        }
         a = a * a % m;
         b >>= 1;
    }
    return res;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        ll a,b,c;cin >> a >> b >> c;
        ll res = binpow(b,c,MOD-1);
        ll ans = binpow(a,res,MOD);
        cout << ans << '\n';
    }
    return 0;
}
