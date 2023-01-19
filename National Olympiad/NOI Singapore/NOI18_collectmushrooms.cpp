#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define ld long double
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
    int r,c,d,k;cin >> r >> c >> d >> k;
    vector<vector<int>> ps(r+1,vector<int>(c+1));
    vector<vector<char>> a(r+1,vector<char>(c+1));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
            ps[i][j] = (a[i][j] == 'S');
            ps[i][j]+=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
        }
    }
    int ans = 0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j] == 'M'){
                int i1 = max(i-d,1),j1 = max(j-d,1),i2 = min(r,i+d),j2 = min(c,j+d);
                ans+=(ps[i2][j2]-ps[i1-1][j2]-ps[i2][j1-1]+ps[i1-1][j1-1] >= k) ;
            }
        }
    }
    cout << ans;
    return 0;
}
