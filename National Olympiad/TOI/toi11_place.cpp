#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pi pair<int,int>

vector<int> pa;
priority_queue<pair<int,pi>> q;
int root(int i){
    if(pa[i] == i) return i;
    return pa[i]=root(pa[i]);
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    ll ans = 0;
    pa.resize(n);
    for(int i=0;i<m;i++){
        int s,d,l;cin >> s >> d >> l;
        q.push({l-1,{s-1,d-1}});
    }
    for(int i=0;i<n;i++){
        pa[i] = i;
    }
    while(!q.empty()){
        int l = q.top().first;
        int s = q.top().second.first;
        int d = q.top().second.second;
        q.pop();
        if(root(s) != root(d)){
            ans+=l;
            pa[root(s)] = pa[root(d)];
        }
    }
    cout << ans << '\n';
    return 0;
}
