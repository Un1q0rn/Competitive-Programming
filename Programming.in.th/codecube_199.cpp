#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define pi pair<ll,ll>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
#define sz(x) (int)x.size()

const int N = 1e5+100;
struct A{
    int u,v;
    ll w;
    int idx;
    bool operator < (const A&o) const {
        return w<o.w;
    }
};
priority_queue<A> pq;
int pa[N];
int root(int i){
    if(pa[i] == i) return i;
    return pa[i] = root(pa[i]);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=1;i<=n;i++) pa[i] = i;
    for(int i=0;i<m;i++){
        int u,v,w;cin >> u >> v >> w;
        pq.push({u,v,w,i+1});
    }
    int t;cin >> t;
    ll ans = 0;
    set<int> ord;
    int ch = 0;
    while(!pq.empty()){
        int u = pq.top().u,v = pq.top().v,i = pq.top().idx;
        ll w= pq.top().w;
        pq.pop();
        if(root(u) == root(v)){
            if(!ch){
                ord.insert(i);
                ans+=w;
                ch = 1;
            }
            continue;
        }
        pa[root(u)] = pa[root(v)];
        ord.insert(i);
        ans += w;
    }
    if(sz(ord) < n){
        cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';
    if(t==2) for(auto it=ord.begin();it!=ord.end();it++) cout << *it << ' ';
    return 0;
}
