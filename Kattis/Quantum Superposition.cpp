#include <bits/stdc++.h>
using namespace std;
 
#define ld long double 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

const int N = 1e3;
const int M = 2e3;
vector<int> adj1[N+10],adj2[N+10],back1[N+10],back2[N+10];
bitset<M+10> dp1[N+10],dp2[N+10],ans;
int ind1[N+10],ind2[N+10],n1,m1,n2,m2;
void topo(int n,vector<int> adj[],vector<int> back[],int ind[],bitset<M+10> dp[]){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!ind[i]) q.push(i);
    }
    while(sz(q)){
        int u = q.front();
        q.pop();
        for(auto v:adj[u]){
            if(--ind[v] == 0) q.push(v);
        }
        if(sz(back[u]) == 0) dp[u][0] = 1;
        for(auto v:back[u]){
            dp[u] |= (dp[v] << 1);
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n1 >> n2 >> m1 >> m2;
    for(int i=0;i<m1;i++){
        int u,v;cin >> u >> v;
        adj1[u].push_back(v);
        back1[v].push_back(u);
        ind1[v]++;
    }
    for(int i=0;i<m2;i++){
        int u,v;cin >> u >> v;
        adj2[u].push_back(v);
        back2[v].push_back(u);
        ind2[v]++;
    }
    topo(n1,adj1,back1,ind1,dp1);
    topo(n2,adj2,back2,ind2,dp2);
    for(int i=0;i<=N;i++){
        if(dp1[n1][i]) ans |= (dp2[n2] << i);
    }
    int q;cin >> q;
    while(q--){
        int x;cin >> x;
        cout << (ans[x] ? "Yes":"No") << '\n';
    }
    return 0;
}
