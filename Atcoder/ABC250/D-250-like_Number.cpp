#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(a,b) for(int i=a;i<=b;i++)
#define vi(x)  vector<x>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int
const int MOD = 1e9+7;
ll gcd(ll a,ll b){
    if(!(a%b)) return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
const int N = 1e6+10;
vector<ll> prime;
void sieve(){
    vector<bool> ch(N,false);
    for(int i=2;i<N;i++){
        if(ch[i]) continue;
        prime.pb(i);
        for(int j=i;j<N;j+=i) ch[j] = true;
    }
}
ll f(ll p,ll q){
    double est = 1;
    est = q*q*q;
    est*=p;
    if(est > 4e18) return 4e18;
    return p*q*q*q;
}
void solve(){
    sieve();
    ll n;cin >> n;
    ll ans=0;
    int q = sz(prime)-1;
    for(int p=0;p<sz(prime);p++){
        while(p<q && f(prime[p],prime[q]) > n) q--;
        if(p>=q) break;
        ans+=(q-p);
    }
    cout << ans;
} 

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    //int t;cin >> t;
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
