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
    setIO("balancing");
    int n,b;cin >> n >> b;
    vi(pi) a(n);
    for(auto &[e,r]:a){
        cin >> e >> r;
    }
    int ans = n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x = a[i].f+1;
            int y = a[j].s+1;
            int downleft=0,downright=0,upleft=0,upright=0;
            for(int k=0;k<n;k++){
                if(a[k].f < x && a[k].s < y){
                    downleft++;
                }
                else if(a[k].f < x && a[k].s > y){
                    upleft++;
                }
                else if(a[k].f > y && a[k].s > y){
                    upright++;
                }
                else{
                    downright++;
                }
            }
            int mx = max({downleft,downright,upleft,upright});
            ans = min(ans,mx);
        }
    }
    cout << ans;
    return 0;
}
