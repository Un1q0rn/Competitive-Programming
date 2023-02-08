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
struct A{
    int x,y,idx;
};
int main() {
    setIO("");
    int N;cin >> N;
    vector<A> north,east;
    vector<int> stop(N),ans(N);
    for(int i=0;i<N;i++){
        char d;cin >> d;
        int x,y;cin >> x >> y;
        if(d == 'N'){
            north.pb({x,y,i});
        }
        else {
            east.pb({x,y,i});
        }
    }
    sort(all(north),[](auto &a,auto &b){
            if(a.x != b.x) return a.x < b.x;
            return a.y < b.y;
            });
    sort(all(east),[](auto &a,auto &b){
            if(a.y != b.y) return a.y < b.y;
            return a.x < b.x;
            });
    for(auto e:east){
        if(stop[e.idx]) continue; 
        for(auto n:north){
            if(stop[n.idx]) continue;
            if(stop[e.idx]) break;
            int e_dist = n.x-e.x,n_dist = e.y-n.y;
            if(e_dist==n_dist || e_dist < 0 || n_dist < 0) continue ;
            if(e_dist < n_dist){
                stop[n.idx] = 1;
                ans[e.idx]+=ans[n.idx]+1;
            }
            else{
                stop[e.idx] = 1;
                ans[n.idx]+=ans[e.idx]+1;
            }
        }
    }
    for(auto a:ans) cout << a << '\n';
    return 0; 
}
