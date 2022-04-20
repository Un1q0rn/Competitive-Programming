#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back

struct A{
    int u,v,w,r;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
struct B{
    int c,d;
    bool operator < (const B&o) const{
        return d<o.d;
    }
};
vector<int> pa;
priority_queue<A> q;
vector<B> pack;
int n,m,s,d,p;
int root(int i){
    if(pa[i] == i) return i;
    return pa[i] = root(pa[i]);
}
int kruskal(){
    int ans = 0;
    while(!q.empty()){
        int u=q.top().u,v=q.top().v,w=q.top().w;
        q.pop();
        if(root(u)==root(v)) continue;
        pa[root(u)] = pa[root(v)];
        for(int i=0;i<p;i++){
            if(pack[i].c >= w){
                ans+=pack[i].d;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    pa.resize(n+1);
    for(int i=0;i<n;i++) pa[i]=i;
    for(int i=0;i<m;i++){
        int u,v,w,r;cin >> u >> v >> w >> r;
        q.push({u,v,w,r});
        if(r == 1){
            pa[root(u)] = pa[root(v)];
        }
    }
    cin >> p;
    for(int i=0;i<p;i++){
        int c,d;cin >> c >> d;
        pack.push_back({c,d});
    }
    sort(pack.begin(),pack.end());
    cout << kruskal();
    return 0;
}
