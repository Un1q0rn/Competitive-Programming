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
struct cow{
    int x,y,idx;
};
int main() {
    setIO("");
    int n;cin >> n;
    vector<cow> north,east;
    FOR(i,0,n-1){
        char dir;
        int x,y;cin >> dir >> x >> y;
        if(dir == 'N'){
            north.pb({x,y,i});
        }
        else east.pb({x,y,i});
    }
    sort(all(north),[](auto &a,auto &b){return a.x < b.x;});
    sort(all(east),[](auto &a,auto &b){return a.y < b.y;});
    vector<int> ans(n,-1);
    for(auto n:north){
        for(auto e:east){
            if(ans[e.idx] != -1) continue;
            if(n.x > e.x && n.y < e.y){
                int n_dist = e.y-n.y;
                int e_dist = n.x-e.x;
                if(n_dist < e_dist){
                    ans[e.idx] = e_dist;
                }
                else if(e_dist < n_dist){
                    ans[n.idx] = n_dist;
                    break;
                }
            }
        }
    }
    for(auto e:ans){
        if(e == -1) cout << "Infinity\n";
        else cout << e << '\n';
    }
    return 0;
}
