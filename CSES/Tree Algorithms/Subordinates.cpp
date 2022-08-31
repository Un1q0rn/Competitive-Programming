#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
vector<int> adj[N];
int subcnt[N];
void dfs(int u){
    subcnt[u] = 1;
    for(auto v:adj[u]){
        dfs(v);
        subcnt[u]+=subcnt[v];
    }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;cin >> n;
  for(int i=2;i<=n;i++){
      int p;cin >> p;
      adj[p].push_back(i);
  }
  dfs(1);
  for(int i=1;i<=n;i++){
      cout << subcnt[i]-1 << ' ';
  }
  return 0;
}
