#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    vector<ll> a(n);
    ll ps=0;
    a[ps] = 1;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        ps += x;
        a[(ps%n+n)%n]++;
    }
    ll ans = 0;
    for(auto e:a){
        ans+=e*(e-1)/2;
    }
    cout << ans << '\n';
    return 0;
}
