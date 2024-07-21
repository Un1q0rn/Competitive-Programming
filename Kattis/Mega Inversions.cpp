#include <bits/stdc++.h> 
using namespace std;
#define ll long long int

const int N = 1e5+10;
ll a[N],n,inv1[N],inv2[N];

struct BIT{
    vector<ll> f;
    BIT(int n) : f(n+10) {}

    void upd(int i){
        while(i <= n){
            f[i]++;
            i += i & -i;
        }
    }

    ll qry(int i){
       ll res = 0;
        while(i > 0){
            res += f[i];
            i -= i & -i;
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    BIT fen1(n),fen2(n);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        fen1.upd(a[i]);
        inv1[i] = i - fen1.qry(a[i]);
    }
    for(int i=n;i>=1;i--){
        inv2[i] = fen2.qry(a[i] - 1);
        fen2.upd(a[i]);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans += inv1[i] * inv2[i];
    }
    cout << ans;
    return 0;
}
