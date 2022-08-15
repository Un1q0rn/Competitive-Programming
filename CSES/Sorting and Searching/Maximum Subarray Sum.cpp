#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    ll ans = a[1],mn = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,a[i]-mn);
        mn = min(mn,a[i]);
    }
    cout << ans;
    return 0;
}
