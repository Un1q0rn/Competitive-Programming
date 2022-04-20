#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back

struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w<o.w;
    }
};
vector<int> pa;
priority_queue<A> q;
int n,m,s,d,p;;
int root(int i){
    if(pa[i] == i) return i;
    return pa[i] = root(pa[i]);
}
void kruskal(){
    pa.resize(n+1);
    for(int i=1;i<=n;i++) pa[i]=i;
    while(!q.empty()){
        int u=q.top().u,v=q.top().v,w=q.top().w;
        q.pop();
        if(root(u)==root(v)) continue;
        pa[root(u)] = pa[root(v)];
        if(root(s) == root(d)) {
            cout << ceil(p*1.0/(w-1));
            return;
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;cin >> u >> v >> w;
        q.push({u,v,w});
    }
    cin >> s >> d >> p;
    kruskal();
    return 0;
}
