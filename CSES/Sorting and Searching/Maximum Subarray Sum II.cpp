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
    int n,l,r;cin >> n >> l >> r;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    ll ans = -INF;
    multiset<ll> s;
    for(int i=l;i<=n;i++){
        if(i > r) s.erase(s.find(a[i-r-1]));
        s.insert(a[i-l]);
        ans = max(ans,a[i]-*s.begin());
    }
    cout << ans;
    return 0;
}
