#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

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

int x,y,m,ans;
map<int,int> mark;
void play(int sum){
    if(sum > m || mark[sum]) return ;
    mark[sum] = 1;
    ans = max(ans,sum);
    play(sum+x);
    play(sum+y);
}

int main() {
    setIO("pails");
    cin >> x >> y >> m;
    play(0);
    cout << ans << '\n';
    return 0;
}
