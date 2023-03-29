#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
const int N = 1e6;
const int MOD = 1e9+7;
ll fac[N+10],inv[N+10];
ll pow(ll x,ll n,ll m){
    x%=m;
    ll res = 1;
    while(n){
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
    for(int i=N;i>=1;i--){
        inv[i-1] = inv[i]*i%MOD;
    }
}
ll compute(int n,vector<int> &cnt){
    ll res = fac[n];
    for(auto e:cnt){
        res=res*inv[e]%MOD;
    }
    return res;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    factorial();
    inverse();
    string s;cin >> s;
    int n = sz(s);
    vector<int> cnt,mark(26);
    for(int i=0;i<n;i++){
        mark[s[i]-'a']++;
    }
    for(auto e:mark){
        if(e>1){
            cnt.pb(e);
        }
    }
    ll ans = compute(n,cnt);
    cout << ans;
    return 0;
}

