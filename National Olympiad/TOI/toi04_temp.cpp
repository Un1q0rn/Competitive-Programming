#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

int n,c,d,a[30][30],ans=INT_MIN;
void dfs(int x,int y,int now){
    if(a[x][y] <= now || a[x][y] == 100 || x < 1 || x > n || y < 1 || y > n) return;
    ans = max(ans,a[x][y]);
    dfs(x+1,y,a[x][y]);
    dfs(x-1,y,a[x][y]);
    dfs(x,y+1,a[x][y]);
    dfs(x,y-1,a[x][y]);
    return ;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> c >> d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[j][i];
        }
    }
    ans = a[c][d];
    dfs(c+1,d,a[c][d]);
    dfs(c-1,d,a[c][d]);
    dfs(c,d-1,a[c][d]);
    dfs(c,d+1,a[c][d]);
    cout << ans << '\n';
    return 0;
}
