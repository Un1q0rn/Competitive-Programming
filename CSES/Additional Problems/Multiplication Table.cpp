#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
#define s second
#define f first
int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n;cin >> n;
    ll l = 0,r = n*n;
    while(l < r){
        ll mid = l+((r-l)>>1);
        ll cnt = 0;
        for(int i=1;i<=n;i++){
            cnt += min(n,mid/i);
        }
        if(cnt >= (n*n+1)/2){
            r = mid;
        }
        else l = mid+1;
    }
    cout << r;
    return 0;
}
