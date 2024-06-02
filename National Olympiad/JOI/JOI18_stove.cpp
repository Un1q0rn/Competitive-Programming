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
    int n,k;cin >> n >> k;
    vector<int> a(n),dif;
    for(auto &e:a) cin >> e;
    for(int i=1;i<n;i++){
        dif.push_back(a[i]-a[i-1]-1);
    }
    sort(all(dif));
    int ans = n;
    for(int i=0;i<n-k;i++){
        ans+=dif[i];
    }
    cout << ans;
    return 0;
}
