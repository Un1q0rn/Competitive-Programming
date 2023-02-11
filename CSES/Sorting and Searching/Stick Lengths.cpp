#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define ld long double
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n;cin >> n;
    vector<ll> a(n);
    for(auto &e:a){
        cin >> e;
    }
    sort(all(a));
    ll ans = 0;
    for(auto e:a){
        ans += (abs(a[n/2]-e));
    }
    cout << ans;
    return 0;
}
