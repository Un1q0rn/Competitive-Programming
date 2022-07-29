#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
ll gcd(ll a,ll b){
    if(!(a%b)) return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
void solve(){
    int q;cin >> q;
    deque<pair<ll,ll>> a;
    while(q--){
        int opr;cin >> opr;
        if(opr == 1){
            ll x,c;cin >> x >> c;
            a.pb({c,x});
        }
        else{
            ll c;cin >> c;
            ll sum = 0;
            while(c > 0){
                ll k = min(c,a.front().f);
                sum+=a.front().s*k;
                c-=k;
                a.front().f-=k;
                if(a.front().f == 0){
                    a.pop_front();
                }
            }
            cout << sum << '\n';
        }
    }
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
