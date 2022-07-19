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
const int mod = 1e9+7;
ll gcd(ll a,ll b){
    if(!(a%b)) return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
void solve(){
    int n,q;cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    string s(n,'0');
    int x = 0;
    for(int i=n-1;i>=0;i--){
        if(x >= a[i]){
            s[i] = '1';
        }
        else if(x < q){
            x++;
            s[i] = '1';
        }
    }
    cout << s << '\n';
} 

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t;cin >> t;
    //int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
