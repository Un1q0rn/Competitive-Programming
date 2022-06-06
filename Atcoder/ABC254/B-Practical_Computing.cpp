#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
int pas[35][35];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    n--;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j == 0 || j == i) pas[i][j] = 1;
            else{
                pas[i][j] = pas[i-1][j-1]+pas[i-1][j];
            }
            cout << pas[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

