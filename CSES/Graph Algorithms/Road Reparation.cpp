#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

const int N = 1e5+100;
struct A{
    int u,v;
    ll w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
priority_queue<A> pq;
int pa[N],n,m,cnt=1;
int root(int i){
    if(pa[i] == i) return i;
    return pa[i] = root(pa[i]);
}
ll kruskal(){
    ll ans = 0;
    for(int i=1;i<=n;i++) pa[i] = i;
    while(!pq.empty()){
        int u = pq.top().u,v = pq.top().v;
        ll w = pq.top().w;
        pq.pop();
        if(root(u) == root(v)) continue;
        pa[root(u)] = pa[root(v)];
        ans+=w;
        cnt++;
    }
    return ans;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        ll w;cin >> w;
        pq.push({u,v,w});
    }
    ll ans = kruskal() ;
    if(cnt == n)cout << ans << '\n';
    else cout << "IMPOSSIBLE" << '\n';
    return 0;
}
