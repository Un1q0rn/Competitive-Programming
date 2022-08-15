#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[1010][1010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin >> n >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char x;cin >> x;
            a[i][j] = (x == '*');
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    while(q--){
        int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
        int res = a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
        cout << res << '\n';
    }
    return 0;
}
