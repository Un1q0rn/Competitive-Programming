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
    int n;cin >> n;
    vector<ll> a(n),b(n);
    for(auto &e:a) cin >> e;
    for(auto &e:b) cin >> e;
    sort(all(a));
    sort(all(b));
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-b[i]);
    }
    cout << ans << '\n';
    return 0;
}
