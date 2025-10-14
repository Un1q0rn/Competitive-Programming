#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) begin(x),end(x);

const int MAXN = 2e5 + 10;
const int LOG = 18;

int up[MAXN][LOG];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q;cin >> n >> q;

    for(int i = 2;i<=n;i++){
        cin >> up[i][0];
    }

    for(int j = 1;j < LOG;j++){
        for(int i = 1;i <= n;i++){
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    while(q--){
        int x,k;cin >> x >> k;

        for(int i = 0;i < LOG;i++){
            if(k & (1 << i)){
                x = up[x][i];
            }
        }

        if(x == 0){
            cout << -1 << '\n';
        }
        else cout << x << '\n';
    }
    return 0;
}
