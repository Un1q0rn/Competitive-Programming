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
void solve(){
    int a=11,b = 0,c = 11,d = 0;
    FOR(i,1,10){
        FOR(j,1,10){
            char x;cin >> x;
            if(x == '#'){
                a = min(i,a);
                b = max(i,b);
                c = min(j,c);
                d = max(j,d);
            }
        }
    }
    cout << a << ' ' << b << '\n' << c << ' ' << d;
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

