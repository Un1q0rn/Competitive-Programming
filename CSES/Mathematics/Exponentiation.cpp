#include <bits/stdc++.h> 
using namespace std; 

#define ll long long int 
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
ll gcd(ll a,ll b){
    return b == 0 ? a:gcd(b,a%b);
}
ll binpow(ll a,ll b,ll n) {
    a%=n;
    ll res = 1;
    while(b){
        if(b%2){
            res = res*a%n;
        }
        a = a*a%n;
        b/=2;
    }
    return res;
}
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t;cin >> t;
    while(t--){
        int a,b;cin >> a >> b;
        cout << binpow(a,b,1e9+7) << '\n';
    }
    return 0;
}

