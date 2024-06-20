#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll n,k;cin >> n >> k;
    vector<ll> a(k);
    for(auto &e:a) cin >> e;
    ll ans = 0;
    for(int i=1;i<(1<<k);i++){
        ll res = n,cnt = 0;
        for(int j=0;j<k;j++){
            res /= ((1<<j) & i ? a[j]:1);
            if((1<<j) & i) cnt++;
        }
        ans += (cnt%2 ? 1:-1) * res;
    }
    cout << ans;
    return 0;
}
