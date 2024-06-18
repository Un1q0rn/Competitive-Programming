#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
#define s second
#define f first

const int N = 2e5+10;
int p[N],ans[N],vis[N];
queue<int> q;
int n,cnt;
void dfs(int u){
    q.push(u);
    if(vis[u]){
        cnt += ans[u];
        return ;
    }
    vis[u] = 1;
    cnt++;
    dfs(p[u]);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        cnt = 0;
        dfs(i);
        int cycle = 1;
        while(sz(q)){
            if(q.front() == q.back()) cycle = 0;
            ans[q.front()] = cnt;
            cnt -= cycle;
            q.pop();
        }
    }
    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    return 0;
}
