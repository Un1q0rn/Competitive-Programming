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
    ll s,t,c;
};
struct B{
    ll a,b,p,m;
};
ll cnt;
ll N,M,ans=1e18,cost;
vector<A> cow;
vector<B> air;
vector<int> mark;
map<vector<int>,int> ma;
ll stall[110];
bool check(){
    for(int i=0;i<N;i++){
        for(int j=cow[i].s;j<=cow[i].t;j++){
            if(stall[j] < cow[i].c) return false;
        }
    }
    return true;
}
void solve(){
    if(ma[mark]) return ;
    ma[mark] = 1;
    for(int i=0;i<M;i++){
        if(mark[i]) continue;
        mark[i] = 1;
        cost+=air[i].m;
        for(int j=air[i].a;j<=air[i].b;j++){
            stall[j]+=air[i].p;
        }
        if(check()) ans = min(ans,cost);
        solve();
        cost-=air[i].m;
        for(int j=air[i].a;j<=air[i].b;j++){
            stall[j]-=air[i].p;
        }
        mark[i] = 0;
    }
}
int main() {
    setIO("");
    cin >> N >> M;
    mark.resize(M);
    for(int i=0;i<N;i++){
        ll s,t,c;cin >> s >> t >> c;
        cow.pb({s,t,c});
    }
    for(int i=0;i<M;i++){
        ll a,b,p,m;cin >> a >> b >> p >> m;
        air.pb({a,b,p,m});
    }
    for(int i=0;i<M;i++){
        mark[i] = 1;
        cost += air[i].m;
        for(int j=air[i].a;j<=air[i].b;j++){
            stall[j]+=air[i].p;
        }
        if(check()) ans = min(ans,cost);
        solve();
        cost-=air[i].m;
        for(int j=air[i].a;j<=air[i].b;j++){
            stall[j]-=air[i].p;
        }
        mark[i] = 0;
    }
    cout << ans;
    return 0;
}
