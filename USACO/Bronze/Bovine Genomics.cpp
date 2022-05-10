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

int main() {
    setIO("cownomics");
    int n,m;cin >> n >> m;
    string cows1[n],cows2[n];
    for(int i=0;i<n;i++){
        cin >> cows1[i];
    }
    for(int i=0;i<n;i++){
        cin >> cows2[i];
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        int check = 0;
        for(int j=0;j<n && !check;j++){
            for(int k=0;k<n && !check;k++){
                if(cows1[j][i] == cows2[k][i]){
                    check = 1;
                }
            }
        }
        if(!check) ans++;
    }
    cout << ans;
    return 0;
}
