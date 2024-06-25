#include <bits/stdc++.h>
using namespace std;
 
 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

ll gcd(ll a,ll b) {return b == 0 ? a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a / gcd(a,b) * b;}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> ind(n);
    while(m--){
        int u,v;cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        ind[v]++;
    }
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<n;i++){
        if(ind[i] == 0) q.push(i);
        sort(all(adj[i]));
    }
    vector<int> ans;
    while(sz(q)){
        int u = q.top();
        q.pop();
        ans.push_back(u);
        for(auto v:adj[u]){
            if(--ind[v] == 0) q.push(v);
        }
    }
    if(sz(ans) == n){
        for(auto e:ans) cout << e+1 << ' ';
    }
    else{
        cout << "Sandro fails.";
    }
    return 0;
}
