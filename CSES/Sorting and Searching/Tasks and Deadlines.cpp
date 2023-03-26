#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<pair<int,int>> a(n);
    for(auto &e:a){
        cin >> e.first >> e.second;
    }
    sort(all(a));
    ll ans = 0,total = 0;
    for(auto [d,t]:a){
        total += d;
        ans += t-total;
    }
    cout << ans;
    return 0;
}
