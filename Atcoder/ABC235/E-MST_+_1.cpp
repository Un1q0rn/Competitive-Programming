#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()
const int N = 2e5+10;
struct A{
    int u,v,w,idx;
    bool operator < (const A&o) const{
        return w<o.w;
    }
};
int pa[N],mark[N],n,m,q;
vector<A> edges;
int root(int i){
    if(pa[i]==i) return i;
    return pa[i] = root(pa[i]);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++) pa[i] = i;
    while(m--){
        int u,v,w;cin >> u >> v >> w;
        edges.pb({u,v,w,-1});
    }
    for(int i=1;i<=q;i++){
        int u,v,w;cin >> u >> v >> w;
        edges.pb({u,v,w,i});
    }
    sort(all(edges));
    for(auto [u,v,w,idx]:edges){
        if(idx != -1){
            mark[idx] = !(root(u) == root(v));
        }
        else{
            if(root(u) == root(v)) continue;
            pa[root(u)] = root(v);
        }
    }
    for(int i=1;i<=q;i++){
        if(mark[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
