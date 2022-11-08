#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define vi(x)  vector<x>
#define pb push_back
#define pf push_front
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
ll gcd(ll a,ll b){
    return b == 0 ? a:gcd(b,a%b);
}
const ll MOD = 998244353;
void solve(){
    ll a,b,c,d,e,f;cin >> a >> b >> c >> d >> e >> f;
    a%=MOD,b%=MOD,c%=MOD,d%=MOD,e%=MOD,f%=MOD;
    ll ans = (((((a*b)%MOD)*c)%MOD)-((((d*e)%MOD)*f)%MOD)+MOD)%MOD;
    cout << ans;
}

bool multi = false;

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
