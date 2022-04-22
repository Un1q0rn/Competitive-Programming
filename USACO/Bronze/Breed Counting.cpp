#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}


int main() {
    setIO("bcount");
    int n,q;cin >> n >> q;
    vector<ll> h(n+1,0),g(n+1,0),j(n+1,0);
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        if(x == 1) h[i] += 1; 
        if(x == 2) g[i] += 1;
        if(x == 3) j[i] += 1;
        h[i]+=h[i-1];
        g[i]+=g[i-1];
        j[i]+=j[i-1];
    }
    while(q--){
        int l,r;cin >> l >> r;
        cout << h[r]-h[l-1] << ' ' << g[r]-g[l-1] << ' ' << j[r]-j[l-1] << '\n';
    }
    return 0;
}
