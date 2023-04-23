#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
#define s second
#define f first

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<pair<ll,ll>> a(n);
    for(auto &[x,y]:a){
        cin >> x >> y;
        x/=2;
        y/=2;
    }
    sort(all(a),greater<pair<ll,ll>>());
    ll mxy = 0,ans = 0;
    for(auto &[x,y]:a){
        if(y <= mxy) continue;
        ans += x*(y-mxy);
        mxy = y;
    }
    cout << ans*4;
    return 0;
}
