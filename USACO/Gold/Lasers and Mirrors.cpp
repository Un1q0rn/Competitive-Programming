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

const int inf = 1e9;
int main() {
    setIO("lasers");
    int n;cin >> n;
    vector<int> x(n + 2),y(n + 2);
    array<map<int,vector<int>>,2> a;
    for(int i=0;i<n + 2;i++){
        cin >> x[i] >> y[i];
        a[0][x[i]].push_back(i);
        a[1][y[i]].push_back(i);
    }
    vector<int> dist(n + 2,inf);
    dist[0] = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    q.push({0,1});
    while(sz(q)){
        int idx = q.front().first;
        int dir = q.front().second;
        q.pop();
        int u = (dir ? y[idx] : x[idx]);
        for(auto v:a[dir][u]){
            if(dist[v] == inf){
                dist[v] = dist[idx] + 1;
                q.push({v,dir ^ 1});
            }
        }
    }
    cout << (dist[1] != inf ? dist[1] - 1 : -1);
    return 0;
}
