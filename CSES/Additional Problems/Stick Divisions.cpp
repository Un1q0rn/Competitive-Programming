#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    ll x,n;cin >> x >> n;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(int i=0;i<n;i++){
        ll a;cin >> a;
        pq.push(a);
    }
    ll ans = 0;
    while(sz(pq) > 1){
        ll a = pq.top();
        pq.pop();
        a += pq.top();
        pq.pop();
        ans += a;
        pq.push(a);
    }
    cout << ans ;
    return 0;
}
