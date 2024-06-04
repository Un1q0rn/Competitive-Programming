#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()

const int N = 2e5+10;
vector<ll> adj[N],ans(N),cnt(N);
int n;
void dfs1(int u){
    cnt[u] = 1;
    for(auto v:adj[u]){
        dfs1(v);
        cnt[u] += cnt[v];
    }
}
void dfs2(int u){
    ans[u] += cnt[u];
    for(auto v:adj[u]){
        dfs2(v);
        ans[u] += ans[v];
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<n;i++){
        int x;cin >> x;
        x--;
        adj[x].push_back(i);
    }
    dfs1(0);
    dfs2(0);
    for(int i=0;i<n;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
