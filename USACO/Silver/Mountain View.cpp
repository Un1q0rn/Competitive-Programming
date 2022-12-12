#include <bits/stdc++.h> 
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
#define setdecimal(x) cout << fixed << setprecision(x)

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
    setIO("mountains");
    int n;cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int x,y;cin >> x >> y;
        a.pb({x-y,x+y});
    }
    sort(all(a),[&](const pi&a,const pi&b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    int ans = 0,mx = -1;
    for(auto &e:a){
        if(e.second > mx){
            mx = e.second;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
