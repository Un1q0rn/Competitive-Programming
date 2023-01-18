#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n;
    while(cin >> n){ 
        vector<vector<int>> a(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> a[i][j];
                a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            }
        }
        int ans = -1e9-10;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int ii=1;ii<=i;ii++){
                    for(int jj=1;jj<=j;jj++){
                        int res = a[i][j]-a[ii-1][j]-a[i][jj-1]+a[ii-1][jj-1];
                        ans = max(res,ans);
                    }
                }
            }
        }
        cout << ans << '\n';  
    }
    return 0;
}
