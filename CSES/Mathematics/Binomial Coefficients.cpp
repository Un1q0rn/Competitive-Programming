#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
const int MOD = 1e9+7;
const int N = 1e6;
ll fac[N+10],inv[N+10];
ll pow(ll x,ll n,ll m){
    x %= m;
    ll res = 1;
    while(n>0){
        if(n%2) res = res*x%m;
        x = x*x%m;
        n>>=1;
    }
    return res;
}
void factorial(){
    fac[0] = 1;
    for(int i=1;i<=N;i++){
        fac[i] = fac[i-1]*i%MOD;
    }
}
void inverse(){
    inv[N] = pow(fac[N],MOD-2,MOD);
    for(int i = N;i >= 1;i--){
        inv[i-1] = inv[i]*i%MOD;
    }
}
ll choose(int n,int r){
    return fac[n]*inv[r]%MOD*inv[n-r]%MOD;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    factorial();
    inverse();
    int q;cin >> q;
    while(q--){
        ll a,b;cin >> a >> b;
        cout << choose(a,b) << '\n';
    }
    return 0;
}
