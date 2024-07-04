#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<pair<int,int>> a(n);
    vector<int> cntx(1e5+10),cnty(1e5+10);
    for(auto &[x,y]:a){
        cin >> x >> y;
        cntx[x]++;
        cnty[y]++;
    }
    ll ans = 0;
    for(auto [x,y]:a){
        ans += 1ll * (cntx[x]-1ll) * (cnty[y]-1ll);
    }
    cout << ans;
    return 0;
}
