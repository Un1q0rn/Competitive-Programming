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
    int a,b,c,d,e,f,x;cin >> a >> b >> c >> d >> e >> f >> x;
    int now = 0;
    int taka=0,ao=0;
    int cntwalk=0,cntrest=0;
    while(now < x){
        if(now%(a+c) < a) taka+=b;
        now++;
    }
    now = 0;
    while(now < x){
        if(now%(d+f) < d) ao+=e;
        now++;
    }
    if(taka > ao) cout << "Takahashi";
    else if(ao > taka) cout << "Aoki";
    else cout << "Draw";
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
