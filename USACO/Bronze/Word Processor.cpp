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
    setIO("word");
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin >> n >> k;
    vector<string> s(n);
    for(auto &e:s){
        cin >> e;
    }
    int word=0;
    for(int i=0;i<n;i++){
        word+=s[i].length();
        if(word <= k){
            if(i) cout << " ";
            cout << s[i];
        }
        else{
            word = s[i].length();
            cout << "\n";
            cout << s[i];
        }
    }
    return 0;
}
