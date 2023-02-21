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
    ll n,t;cin >> n >> t;
    vi(ll) a(n);
    for(auto &e:a) cin >> e;
    ll l = 1,r = 1e18;
    while(l < r){
        ll mid = l+((r-l)>>1);
        ll cnt = 0;
        for(auto e:a){
            cnt+=(mid/e);
            if(cnt > 1e18) break;
        }
        if(cnt < t){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    cout << r;
    return 0;
}
