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
void solve(){
    int w,h,r,c;cin >> w >> h >> r >> c;
    int ans = 0;
    if(r-1 > 0) ans++;
    if(r+1 <= w) ans++;
    if(c-1 > 0) ans++;
    if(c+1 <= h) ans++;
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
