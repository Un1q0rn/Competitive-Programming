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
    setIO("cownomics");
    int n,m;cin >> n >> m;
    vector<string> spotty(n),plain(n);
    for(auto &e:spotty){
        cin >> e;
    }
    for(auto &e:plain){
        cin >> e;
    }
    int ans = 0;
    FOR(i,0,m-1){
        FOR(j,i+1,m-1){
            FOR(k,j+1,m-1){
                int ok = 1;
                set<vector<char>> cow;
                vector<char> s;
                FOR(l,0,n-1){
                    s.pb(spotty[l][i]);
                    s.pb(spotty[l][j]);
                    s.pb(spotty[l][k]);
                    cow.insert(s);
                    s.clear();
                }
                FOR(l,0,n-1){
                    s.pb(plain[l][i]);
                    s.pb(plain[l][j]);
                    s.pb(plain[l][k]);
                    if(cow.find(s) != cow.end()){
                        ok = 0;
                        break;
                    }
                    s.clear();
                }
                if(ok) ans++;
            }
        }
    }
    cout << ans ;
    return 0;
}
