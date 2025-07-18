#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)
#define sz(x) (int)x.size()
#define ul unsigned long long

int gcd(int a,int b) {return b == 0 ? a:gcd(b,a%b);}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;cin >> n >> m;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i] = (ll)(i) * m - a[i];
    }

    vector<ll> lis;
    for(int i=0;i<n;i++){
        if(a[i] < 0) continue;
        int p = upper_bound(all(lis),a[i]) - lis.begin();
        if(p == sz(lis)){
            lis.push_back(a[i]);
        }
        else lis[p] = a[i];
    }

    cout << n - sz(lis);
    return 0;
}
