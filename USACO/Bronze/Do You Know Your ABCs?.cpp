#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>;
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

int main() {
    //setIO("word");
    cin.tie(0)->sync_with_stdio(0);
    vector<int> a(7);
    for(auto &e:a){
        cin >> e;
    }
    sort(all(a));
    cout << a[0] << " " << a[1] << " ";
    if(a[2] != a[0]+a[1]) cout << a[2];
    else cout << a[3];
    return 0;
}
