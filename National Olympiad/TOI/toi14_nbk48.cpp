#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define pb push_back

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,q;cin >> n >> q;
    vector<pair<ll,ll>> a(n+1);
    vector<ll> b(n+1);
    a[0] = {0,0};
    for(ll i=1;i<=n;i++){
        cin >> a[i].first;
        a[i].second = i;
        a[i].first += a[i-1].first;
    }
    sort(a.begin(),a.end());
    for(ll i=1;i<=n;i++){
        a[i].second = max(a[i].second,a[i-1].second);
    }
    while(q--){
        ll k;cin >> k;
        auto it = upper_bound(a.begin(),a.end(),make_pair(k,LLONG_MAX));
        it--;
        cout << it->second << '\n';
    }
    return 0;
}
