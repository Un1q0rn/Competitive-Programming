#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define sz(x) (int)x.size()
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int m,n;
    while(cin >> m >> n){
        vector<vector<int>> a(m+1,vector<int>(n+1)),b(n+1,vector<int>(m+1));
        for(int i=1;i<=m;i++){
            int r;cin >> r;
            vector<int> order(r);
            for(int j=0;j<r;j++){
                cin >> order[j];
            }
            for(int j=0;j<r;j++){
                int x;cin >> x;
                a[i][order[j]] = x;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                b[i][j] = a[j][i];
            }
        }
        cout << n << ' ' << m << '\n';
        for(int i=1;i<=n;i++){
            vector<int> order;
            for(int j=1;j<=m;j++){
                if(b[i][j] != 0) order.push_back(j);
            }
            cout << sz(order) ;
            for(int j=0;j<sz(order);j++){
                cout << ' ' << order[j];
            }
            cout << '\n';
            for(int j=0;j<sz(order);j++){
                if(j) cout << ' ';
                cout << b[i][order[j]];
            }
            cout << '\n';
        }
    }
    return 0;
}
