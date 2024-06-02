#include <bits/stdc++.h> 
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
#define setdecimal(x) cout << fixed << setprecision(x)

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
int main() {
    setIO("lineup");
    int n;cin >> n;
    map<string,int> m;
    vector<string> s{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    vector<vector<int>> g(8);
    sort(all(s));
    for(int i=0;i<8;i++){
        m[s[i]] = i;
    }
    for(int i=0;i<n;i++){
        string c1,t,c2;
        cin >> c1 >> t >> t >> t >> t >> c2 ;
        g[m[c1]].push_back(m[c2]);
        g[m[c2]].push_back(m[c1]);
    }
    vector<int> ans,vis(8);
    queue<int> q;
    for(int i=0;i<8;i++){
        if(vis[i] || sz(g[i]) > 1) continue;
        vis[i] = 1;
        ans.push_back(i);
        q.push(i);
        while(sz(q)){
            int u = q.front();
            for(auto v:g[u]){
                if(vis[v]) continue;
                q.push(v);
                ans.push_back(v);
                vis[v] = 1;
            }
            q.pop();
        }
    }
    for(auto e:ans) cout << s[e] << '\n';
    return 0;
}
