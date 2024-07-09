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
const int inf = 20;
int main() {
    setIO("");
    int n,c;cin >> c >> n;
    vector<int> dist(1<<c,inf),a;
    queue<int> q;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        int x = 0;
        for(int j=0;j<c;j++){
            if(s[j] == 'G') x |= (1 << j);
        }
        dist[x] = 0;
        q.push(x);
        a.push_back(x);
    }
    while(sz(q)){
        int x = q.front();
        q.pop();
        for(int i=0;i<c;i++){
            if(dist[x ^ (1 << i)] > dist[x] + 1){
                dist[x ^ (1 << i)] = dist[x] + 1;
                q.push(x ^ (1 << i));
            }
        }
    }
    for(auto e:a){
        cout << c - dist[e ^ ((1 << c) - 1)] << '\n';
    }
    return 0;
}
