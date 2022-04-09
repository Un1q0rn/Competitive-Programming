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
    setIO("cowsignal");
    cin.tie(0)->sync_with_stdio(0);
    int a,b,c;cin >> a >> b >> c;
    for(int i=0;i<a;i++){
        string sl = "";
        for(int j=0;j<b;j++){
            char s;cin >> s;
            for(int k=0;k<c;k++) sl += s;
        }
        for(int j=0;j<c;j++){
            cout << sl << "\n";
        }
    }    
    return 0;
}
