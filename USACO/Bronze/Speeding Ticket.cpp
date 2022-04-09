#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>;
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
    setIO("speeding");
    int n,m;cin >> n >> m;
    vector<pair<int,int>> a(n),b(m);
    for(int i=0;i<n;i++){
        cin >> a[i].f>> a[i].s;
        if(i) a[i].f+=a[i-1].f;
    }
    for(int i=0;i<m;i++){
        cin >> b[i].f >> b[i].s;
        if(i) b[i].f+=b[i-1].f;
    }
    int now = 0,state = 0,ans = 0;
    for(int i=0;i<=100;i++){
        if(i > b[state].f){
            state++;
        }
        if(i > a[now].f){
            now++;
        }
        ans = max(b[state].s-a[now].s,ans);
    }
    cout << ans << endl;
    return 0;
}
