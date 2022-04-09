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
    setIO("buckets");
    cin.tie(0)->sync_with_stdio(0);
    vector<string> s(10);
    int Ri,Rj,Bi,Bj,Li,Lj;
    for(int i=0;i<10;i++){
        cin >> s[i];
        for(int j=0;j<10;j++){
            if(s[i][j] == 'R'){
                Ri = i;
                Rj = j;
            }
            if(s[i][j] == 'B'){
                Bi = i;
                Bj = j;
            }
            if(s[i][j] == 'L'){
                Li = i;
                Lj = j;
            }
        }
    }
    int ans = abs(Bi-Li)+abs(Bj-Lj)-1;
    if(Ri == Li && Li == Bi && ((Rj < Lj && Rj > Bj) || (Rj > Lj && Rj < Bj))){
        ans+=2;
    }
    else if(Rj == Lj && Lj == Bj && ((Ri < Li && Ri > Bi) || (Ri > Li && Ri < Bi))){
        ans+=2;
    }
    cout << ans;
    return 0;
}
