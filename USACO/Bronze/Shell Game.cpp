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

vector<int> a1(3),a2(3),a3(3);
int p1,p2,p3;

int main() {
    setIO("shell");
    int q;cin >> q;
    a1[0] = 1,a2[1] = 1,a3[2] = 1;
    while(q--){
        int a,b,c;cin >> a >> b >> c;
        a--,b--,c--;
        swap(a1[a],a1[b]);
        swap(a2[a],a2[b]);
        swap(a3[a],a3[b]);
        if(a1[c] == 1) p1++;
        if(a2[c] == 1) p2++;
        if(a3[c] == 1) p3++;
    }
    cout << max({p1,p2,p3});
    return 0;
}
