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
ll gcd(ll a,ll b){
    return b == 0 ? a:gcd(b,a%b);
}
const int MOD = 1e9+7;
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n;cin >> n;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    vector<vector<char>> grid(n+1,vector<char>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> grid[i][j];
        }
    }
    a[1][1] = (grid[1][1] != '*');
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j] == '*') continue;
            a[i][j]+=a[i-1][j]+a[i][j-1];
            a[i][j]%=MOD;
        }
    }
    cout << a[n][n];
    return 0;
}
