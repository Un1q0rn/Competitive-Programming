#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

const int N = 50;
vector<int> adj[N];
int visited[N],cyclic[N],ans;
void dfs(int cur,int node){
    visited[cur] = 1;
    for(auto x:adj[cur]){
        if(x == node){
            cyclic[x] = 1;
            return;
        }
        if(!visited[x]){
            dfs(x,node);
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,sa,sb;cin >> a >> b >> sa >> sb;
        if(sa > sb) adj[b].pb(a);
        else adj[a].pb(b);
    }
    for(int i=1;i<=n;i++){
        fill(begin(visited),end(visited),0);
        dfs(i,i);
    }
    for(int i=1;i<=n;i++){
        if(cyclic[i]) ans++;
    }
    cout << ans;
    return 0;
}
